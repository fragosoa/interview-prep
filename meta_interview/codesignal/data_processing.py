from collections import defaultdict
from enum import Enum
from datetime import datetime

logs = "1 create 10:00, 4 create 10:00, 1 delete 16:00, 3 create 10:00, 4 delete 15:00, 3 delete 15:00, 2 create 10:00, 2 delete 15:00"

class OperationType(Enum):
    CREATE = "create"
    DELETE = "delete"

class LogParser:
    def __init__(self,logs):
        self.logs = logs
        self.operation_history = defaultdict(list)

    def _preprocess_logs(self):
        entries = self.logs.split(",")
        format = "%H:%M"

        for entry in entries:
            id,operation,timestamp = entry.strip().split(" ")
            if operation == OperationType.CREATE.value:
                self.operation_history[int(id)].append({
                    "start": datetime.strptime(timestamp,format),
                    "end": None
                })
            elif operation == OperationType.DELETE.value:
                self.operation_history[int(id)][len(self.operation_history[id])-1]["end"] = datetime.strptime(timestamp,format)

    def analyze_logs(self):
        self._preprocess_logs()
        result = []
        for id in self.operation_history.keys():
            sum_deltas = 0
            for entry in self.operation_history[id]:
                delta = (entry["end"]-entry["start"])
                delta_in_hours = delta.total_seconds()/3600
                sum_deltas += delta_in_hours
            if not result or sum_deltas > result[0][1]:
                result = []
                result.append((id,sum_deltas))
            elif sum_deltas == result[0][1]:
                result.append((id,sum_deltas))
        return sorted(result, key=lambda x: x[0]) 


parser = LogParser(logs)
result = parser.analyze_logs()
print(result)