# 이것이 취업을 위한 코딩테스트다
# https://www.acmicpc.net/problem/14501
# 1

n = int(input())
t = []
p = []
dp = [0] * (n + 1)
max_value = 0

for _ in range(n):
    x, y = map(int, input().split())
    t.append(x)
    p.append(y)

for i in range(n - 1, -1, -1):
    time = t[i] + i
    if time <= n:
        dp[i] = max(p[i] + dp[time], max_value)
        max_value = dp[i]
    else:
        dp[i] = max_value
print(max_value)
