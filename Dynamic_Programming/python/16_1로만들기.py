# 이것이 취업을 위한 코딩테스트다 217p
# https://www.acmicpc.net/problem/1463
# 2

N = int(input())
dp = [0] * (N + 1)

for i in range(2, N + 1):
    dp[i] = dp[i - 1] + 1
    if i % 2 == 0:
        dp[i] = min(dp[i], dp[i // 2] + 1)
    if i % 3 == 0:
        dp[i] = min(dp[i], dp[i // 3] + 1)

print(dp[N])
