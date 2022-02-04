# fast campus 강의
# https://www.acmicpc.net/problem/16769
# 1

C, M = [0, 0, 0], [0, 0, 0]

for i in range(3):
    C[i], M[i] = map(int, input().split())

for i in range(100):
    idx, nxt = i % 3, (i + 1) % 3

    M[idx], M[nxt] = max(M[idx] - (C[nxt] - M[nxt]), 0), min(C[nxt], M[idx] + M[nxt])

for i in M:
    print(i)