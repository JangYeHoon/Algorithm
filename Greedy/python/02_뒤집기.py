# fast campus 강의
# https://www.acmicpc.net/problem/1439
# 2

# 문제 : 정답 바뀌는구간
# 0 1 : 0 0
# 01 10 : 1 1
# 101 010 : 1 2
# 1010 : 2 3
# 10101 : 2 4
# 101010 : 3 5
# 바뀌는구간 + 1 // 2

S, result = input(), 0
for i in range(1, len(S)):
    if S[i] != S[i - 1]:
        result += 1

print((result + 1) // 2)