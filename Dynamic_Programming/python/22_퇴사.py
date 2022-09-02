# 이것이 취업을 위한 코딩테스트다
# https://www.acmicpc.net/problem/14501
# 0

N = int(input())
arr = []
dp = [[0] * (N + 1) for _ in range(N + 1)]
for i in range(N):
    t, p = map(int, input().split())
    arr.append((t, p))
    dp[0][i + 1] = p

for i in range(1, N + 1):
    idx = i
    t = i
    while idx <= N:
        if idx + arr[idx - 1][0] > N:
            break
        dp[i][idx] = dp[i][idx - t] + dp[i - 1][idx]
        t = arr[idx - 1][0]
        idx += t
        if idx < N + 1:
            for j in range(idx - t + 1, idx):
                dp[i][j] = dp[i - 1][j]

print(max(dp[N]))
