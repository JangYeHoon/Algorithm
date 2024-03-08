# 이것이 취업을 위한 코딩테스트다
# https://www.acmicpc.net/problem/15483
# 1

str1 = input()
str2 = input()

str1_len = len(str1)
str2_len = len(str2)

dp = [[0] * (str2_len + 1) for _ in range(str1_len + 1)]

for i in range(1, str1_len + 1):
    dp[i][0] = i
for j in range(1, str2_len + 1):
    dp[0][j] = j

for i in range(1, str1_len + 1):
    for j in range(1, str2_len + 1):
        if str1[i - 1] == str2[j - 1]:
            dp[i][j] = dp[i - 1][j - 1]
        else:
            dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1])

print(dp[str1_len][str2_len])
