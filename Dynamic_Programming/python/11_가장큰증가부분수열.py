# fast campus 강의
# https://www.acmicpc.net/problem/11055
# 1

from copy import deepcopy

N, A = int(input()), list(map(int, input().split()))

# DP[i] : i 까지 왔을 때, 합의 최대
DP = deepcopy(A)
# 정답인 큰 증가 부분 수열 합의 수열 출력을 위한 리스트
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