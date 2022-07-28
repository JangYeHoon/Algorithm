# 개미전사(c++), 바닥공사(c++), 효율적인 화폐 구성(c++)

N, M = map(int, input().split())
dp = [10001] * (M + 1)

arr = []
for _ in range(N):
    arr.append(int(input()))

dp[0] = 0
for i in range(N):
    for j in range(arr[i], M + 1):
        if dp[j - arr[i]] != 10001:
            dp[j] = min(dp[j], dp[j - arr[i]] + 1)

if dp[M] == 10001:
    print(-1)
else:
    print(dp[M])