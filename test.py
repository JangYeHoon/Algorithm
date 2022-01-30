# 수빈이와수열

N = int(input())
B = list(map(int, input().split()))
A = [0] * N

A[0] = B[0]
for i in range(1, N):
    A[i] = B[i] * (i + 1) - sum(A[:i])

for i in range(N):
    print(A[i], end= " ")