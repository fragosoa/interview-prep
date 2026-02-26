class Student:
    def __init__(self,name,age):
        self.name = name
        self.age = age
    
    def __repr__(self):
        return f"{self.name}"
    
    def __lt__(self,other):
        return self.age > other.age
    
class CollegeStudent(Student):
    def __lt__(self,other):
        return self.name < other.name


students = [
    CollegeStudent("Vanessa",27),
    CollegeStudent("Adolfo",28),
    CollegeStudent("Esteban",14),
    CollegeStudent("Nataly",30)
]

students.sort(key=lambda x: x.name)
print(students)

# heap. 
import heapq

minheap = students[:]
heapq.heapify(minheap)

while minheap:
    top = minheap[0]
    heapq.heappop(minheap)
    print(top)
