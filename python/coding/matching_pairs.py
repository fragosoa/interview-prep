
def matching_pairs(s,t):
    n = len(s)

    matches = 0
    mismatches = set()
    s_unmatched = set()
    t_unmatched = set()

    for i in range(n):
        if s[i] == t[i]:
            matches += 1
    
    check_plus_two = False

    for i in range(n):
        if s[i] != t[i]:
            if (t[i],s[i]) in mismatches:
                check_plus_two = True
            mismatches.add((s[i],t[i]))
            s_unmatched.add(s[i])
            t_unmatched.add(t[i])
    if check_plus_two:
        return matches + 2
    #At least one character can be swapped
    if s_unmatched & t_unmatched:
        return matches + 1 
    
    if matches == n:
        if len(set(s)) < n:
            return n
        return n-2

    return matches

print(matching_pairs("abcd","abcd"))