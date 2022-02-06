# fast campus 강의
# https://www.acmicpc.net/problem/17389
# 2

N, S = input(), input()

score, bonus = 0, 0
for idx, OX in enumerate(S):
    if OX == 'O':
        score += idx + 1 + bonus
        bonus += 1
    else:
        bonus = 0

print(score)