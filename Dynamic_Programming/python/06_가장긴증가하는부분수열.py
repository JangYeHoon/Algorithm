# fast campus 강의
# https://www.acmicpc.net/problem/11053
# 1

n = int(input())
array = list(map(int, input().split()))
dp = [1] * n
for i in range(1, n):
    for j in range(0, i):
        if array[j] < array[i]:
            dp[i] = max(dp[i], dp[j] + 1)
print(max(dp))