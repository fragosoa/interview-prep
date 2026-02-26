from collections import Counter,defaultdict

logs ="1 solve 09:00 50, 2 solve 10:00 60, 1 fail 11:00, 3 solve 13:00 40, 2 fail 14:00, 3 solve 15:00 70" 

def preprocess_logs(logs):
    for entry in logs.split(", "):
        parts = entry.split()
        student_id = int(parts[0])
        action = parts[1]
        points = int(parts[3]) if action == "solve" else 0
        yield student_id,action,points

def analyze_competition(logs):
    stats = defaultdict(lambda: {
        "score": 0,
        "success": 0,
        "fail": 0
    })
    
    for student_id,action,points in preprocess_logs(logs):
        if action == 'solve':
            stats[student_id]["score"] += points
            stats[student_id]["success"] += 1
        elif action == 'fail':
            stats[student_id]["fail"] += 1
    
    student_results = [
        (student,metrics["score"],metrics["success"],metrics["fail"])
        for student,metrics in stats.items()
        if metrics["score"] > 0
    ]
    
    return sorted(student_results, key=lambda x: -x[1])
    