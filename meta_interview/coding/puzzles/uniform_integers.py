
def s(x):
    if x <= 0:
        return 0
    digits = len(str(x))
    first = int(str(x)[0])
    uniform_candidate = int(str(first) * digits) # Makes the next 333...
    if uniform_candidate > x:
        first -= 1
    return (digits -1) * 9 + first
 
def getUniformIntegerCountInInterval(A: int, B: int) -> int:
    return s(B) - s(A-1)
    

A = 999999999999
B = 999999999999
res = getUniformIntegerCountInInterval(A=A,B=B)
print(res)