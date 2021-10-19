from copy import deepcopy

N, A = int(input()), list(map(int, input().split()))
DP = deepcopy(A)
rev = [i for i in range(N)]

for i in range(1, N):
    for j in range(i):
        if A[i] > A[j] and DP[i] < A[i] + DP[j]:
            DP[i] = A[i] + DP[j]
            rev[i] = j

print(max(DP))

idx = DP.index(max(DP))
seq = []
while rev[idx] != idx:
    seq.append(A[idx])
    idx = rev[idx]
seq.append(A[idx])
for i in sorted(seq):
    print(i, end=' ')