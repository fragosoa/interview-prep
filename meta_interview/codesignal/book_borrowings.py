from datetime import datetime
from collections import defaultdict

logs = "1 borrow 09:00, 2 borrow 10:00, 1 return 12:00, 3 borrow 13:00, 2 return 15:00, 3 return 16:00"

def preprocess_logs(logs):
    parts = logs.split(", ")
    format = "%H:%M"

    for entry in parts:
        book_id,action,timestamp = entry.split()
        yield book_id,action,datetime.strptime(timestamp,format)

def format_duration(seconds):
    hours = int(seconds//3600)
    minutes = int((seconds%3600) // 60)
    return f"{hours:02d}:{minutes:02d}"
def solution(logs):
    book_borrowings = defaultdict(lambda: {
        "start": None,
        "duration": 0
    })
    for book_id,action,timestamp in preprocess_logs(logs):
        if action == 'borrow':
            book_borrowings[book_id]["start"] = timestamp
        elif action == 'return':
            delta = timestamp - book_borrowings[book_id]["start"]
            book_borrowings[book_id]["duration"] += delta.total_seconds()
    
    max_duration = max(metric["duration"] for metric in book_borrowings.values())
    result = [
        (book_id, format_duration(book["duration"]))
        for book_id,book in book_borrowings.items()
        if book["duration"] == max_duration
    ]
    return sorted(result)

result = solution(logs)
print(result)