# 이것이 취업을 위한 코딩테스트다
# https://www.acmicpc.net/problem/18353
# 1

n = int(input())
arr = list(map(int, input().split()))
arr.reverse()
dp = [1] * n

for i in range(1, n):
    for j in range(i):
        if arr[j] < arr[i]:
            dp[i] = max(dp[i], dp[j] + 1)
print(n - max(dp))
