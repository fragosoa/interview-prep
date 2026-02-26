def getArtisticPhotographCount(N: int, C: str, X: int, Y: int) -> int:
    count = 0
    P = [0]*N
    B = [0]*N
    
    for i in range(N):
        P[i] = P[i-1]
        B[i] = B[i-1]

        if C[i] == 'P':
            P[i] = 1+P[i-1]
        if C[i] == 'B':
            B[i] = 1+B[i-1]
    curr_total = 0
    for (i,c) in enumerate(C):
        if c != 'A':
            continue
        # case PAB
        curr_total = 0
        for k in range(2):
            (left_start,left_end) = (i-Y,i-X)
            (right_start,right_end) = (i+X,i+Y)
            
            count_p = 0
            if left_start-1 < 0 and left_end >= 0:
                count_p = P[left_end]
            if left_start-1 >=0 and left_end >= 0:
                count_p = P[left_end] - P[left_start-1]
            
            count_b = 0
            if right_start-1 < N and right_end >= N:
                count_b = B[N-1] - B[right_start-1]
            if right_start -1 < N and right_end < N:
                count_b = B[right_end] - B[right_start-1]
            
            curr_total += (count_b * count_p)
            P,B = B,P
        
        count += curr_total
        
    return count

N = 5
C = "APABA"
X = 1
Y = 2

res = getArtisticPhotographCount(N=N,C=C,X=X,Y=Y)
print(res)