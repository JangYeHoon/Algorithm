# fast campus 강의
# https://www.acmicpc.net/problem/11055
# 2

from copy import deepcopy

N = int(input())
arr = list(map(int, input().split()))
dp = deepcopy(arr)

for i in range(1, N):
    for j in range(i):
        if arr[j] < arr[i]:
            dp[i] = max(dp[i], dp[j] + arr[i])
print(max(dp))
