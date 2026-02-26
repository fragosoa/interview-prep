arr = [4,3,4,56,6,3]

arr.sort() # in place
#print(arr)

sorted_arr = sorted(arr)
#print(sorted_arr)

# sort by key. 
employees = [
    {
        "name": "Adolfo",
        "age": 28
    },
    {
        "name": "Adolfo",
        "age": 30
    },
    {
        "name": "Vanessa",
        "age": 29
    },
    {
        "name": "Raul",
        "age": 27
    },
]
#print(employees)
# Sorting by different attributes
employees.sort(key=lambda x: x["age"], reverse=True)
employees.sort(key=lambda x: x["name"])

class User:
    def __init__(self,name,age):
        self.name = name
        self.age = age
    def __repr__(self):
        return f"{(self.name,self.age)}"

users = [
    User("Adolfo",28),
    User("Adolfo",30),
    User("Vanessa",27),
    User("Raul",15)
]

users.sort(key=lambda x: x.age)
users.sort(key=lambda x: x.name,reverse=True)
print(users)