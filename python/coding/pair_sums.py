from collections import defaultdict

def numberOfWays(arr,k):
    count = 0
    freqs = defaultdict(int)

    for x in arr:
        target = k-x
        if target in freqs:
            count += (freqs[target])
        freqs[x] += 1

    return count


res = numberOfWays([1, 5, 3, 3, 3],6)
print(res)