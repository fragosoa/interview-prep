lst = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

print(lst[2:5])
print(lst[2:])
print(lst[6:])
print(lst[:6])
print(lst[:])

#step 
print(lst[2:9:2])
print(lst[1::2])
print(lst[::])

print(lst[::-1])
print(lst[-2])
print(lst[-3:])
print(lst[:-3])

# Remover elementos: 

lst = [1,2,3,2,4]
lst.remove(2)
print(lst)

# list comprehesion
lst = [1,2,3,2,4]

lst = [x for x in lst if x != 2]
print(lst)