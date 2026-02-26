# LISTS
# ----------------------------------------------
arr = []
arr.append(1)
# Add multiple elements
arr.extend([1,2,3])
arr.pop(1) ## BY INDEX. This is linear all elements are moved to the left.

#Notas 
'''
>>> arr = []
>>> arr.append(2)
>>> arr
[2]
>>> arr.pop()
2
>>> arr
[]
>>> arr.append([1,3,3])
>>> arr
[[1, 3, 3]]
>>> arr.pop()
[1, 3, 3]
>>> a
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
NameError: name 'a' is not defined
>>> arr
[]
>>> arr.append({1,2,3})
>>> arr
[{1, 2, 3}]
>>> typeof(arr)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
NameError: name 'typeof' is not defined
>>> type(arr)
<class 'list'>
>>> arr.pop()
{1, 2, 3}
>>> arr
[]
>>> arr
[]
>>> arr.append(1)
>>> arr.extend([2,3,4])
>>> ar
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
NameError: name 'ar' is not defined
>>> arr
[1, 2, 3, 4]
>>> abb = []
>>> abb.extend("hello")
>>> abb
['h', 'e', 'l', 'l', 'o']
>>> abb.append("hello")
>>> abb
['h', 'e', 'l', 'l', 'o', 'hello']
>>> l1  = [1,2,3]
>>> l2 = [4,5,6]
>>> l3 = l1+l2
>>> l3
[1, 2, 3, 4, 5, 6]
>>> l3 = l1.extend(l2)
>>> l3
>>> l3
>>> l3 = l1+l2
>>> l3
[1, 2, 3, 4, 5, 6, 4, 5, 6]
>>> l4 = [1,2,3,4,5]
>>> l4
[1, 2, 3, 4, 5]
>>> l4.pop(3)
4
>>> l4
[1, 2, 3, 5]
>>> l4
[1, 2, 3, 5]
>>> l4.remove(5)
>>> l4
[1, 2, 3]
>>> l5 = [-2,-1,0,1,2,3,4,5]
>>> l5.remove(-2)
>>> l5
[-1, 0, 1, 2, 3, 4, 5]
'''

## SETS
# ----------------------------------------------

s = set()
s.add(1)
s.remove(1) # Falla si no existe
s.discard(1) # Mejor cuando no necesitamos saber si hay error. 
s = set({1,2})
t = set({2,3})

#operaciones
s | t # union
s & t # interseccion
s - t # diferencia
s ^ t # diferencia simetrica.

'''
>>> s = set()
>>> s.add(1)
>>> s
{1}
>>> s.add(1)
>>> s
{1}
>>> s.remove(2)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
KeyError: 2
>>> s.discard(2)
>>> s
{1}
>>> 1 in s
True
>>> 2 in s
False
>>> s
{1}
>>> s.add(2)
>>> s
{1, 2}
>>> t = set({2,3})
>>> t
{2, 3}
>>> s & t
{2}
>>> s - t
{1}
>>> s | t
{1, 2, 3}

'''

## DICT

## MISC

