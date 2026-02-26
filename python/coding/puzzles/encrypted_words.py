def findEncryptedWord(s):
    n = len(s)
    if n <= 1:
        return s
    start = 0
    end = n//2
    if n %2 == 0:
        end -= 1
    left = findEncryptedWord(s[start:end])
    right = findEncryptedWord(s[end+1:])
    result = s[end] + left + right 

    return result
    
res = findEncryptedWord("facebook")
print(res)