# fast campus 강의
# https://www.acmicpc.net/problem/1932
# 2

N = int(input())
dp = [[0] * (N + 1) for _ in range(N + 1)]

matrix = [[0] * (N + 1) for _ in range(N + 1)]
for i in range(1, N + 1):
    tmp = list(map(int, input().split()))
    for j in range(1, i + 1):
        matrix[i][j] = tmp[j - 1]

for i in range(1, N + 1):
    for j in range(1, i + 1):
        dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + matrix[i][j]

print(max(dp[-1]))
