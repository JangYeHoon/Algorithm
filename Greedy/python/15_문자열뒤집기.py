# 이것이 취업을 위한 코딩테스트다 313p
# https://www.acmicpc.net/problem/1439
# 2

S = input()

result = 0
for i in range(1, len(S)):
    if S[i - 1] != S[i]:
        result += 1
print((result + 1) // 2)