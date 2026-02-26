from collections import defaultdict
# Leer el archivo y promediar por estudiante: 
'''
id, materia, calificacio
promediar por estudiante
'''
grades = defaultdict(lambda : {
    "sum": 0,
    "count": 0
})
with open("logs.txt", encoding="utf-8") as f:
    for line in f:
        id,subject,note = line.strip().split()
        #print(f"id: {id} - sub: {subject} - note: {note}")
        grades[id]["sum"] += int(note)
        grades[id]["count"] += 1

for student,grade in grades.items():
    avg = float(grade["sum"]/grade["count"])
    print(f"student_id{student} - avg = {avg}%2.0f")
