# fast campus 강의
# https://www.acmicpc.net/problem/1932
# 1

N = int(input())
matrix = [[0 for _ in range(N + 1)] for i in range(N + 1)]
# dp 점화식 : i, j 도착했을 때 최대값
# DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]) + matrix[i][j]
DP = [[0 for _ in range(N + 1)] for i in range(N + 1)]

for i in range(1, N + 1):
    tmp = list(map(int, input().split()))
    for j in range(1, i + 1):
        matrix[i][j] = tmp[j - 1]

for i in range(1, N + 1):
    for j in range(1, i + 1):
        DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]) + matrix[i][j]

print(max(DP[-1]))