from collections import defaultdict

def contains_all_chars(t_freq,s_freq):
    s_keys = s_freq.keys()
    for key in t_freq.keys():
        if key not in s_keys:
            return False
        if s_freq[key] < t_freq[key]:
            return False

    return True

def min_length_substring(s,t):
    t_freq = defaultdict(int)
    s_freq = defaultdict(int)

    for c in t:
        t_freq[c] += 1
    
    start = 0
    n = len(s)
    min_size = 1000000000 
    for end in range(0,n):
        s_freq[s[end]] += 1

        while contains_all_chars(t_freq, s_freq):
            min_size = min(min_size, (end-start+1))
            s_freq[s[start]] -= 1
            if s_freq[s[start]] == 0:
                del s_freq[s[start]]
            start += 1
        
    return min_size if min_size != 1000000000 else -1

if __name__ == '__main__':
    res = min_length_substring(s="dcbefebce",t="fd")
    print(res)