# fast campus 강의
# https://www.acmicpc.net/problem/17224
# 2

N, L, K = map(int, input().split())
easy, hard = 0, 0

for i in range(N):
    sub1, sub2 = map(int, input().split())
    if sub2 <= L:
        hard += 1
    elif sub1 <= L:
        easy += 1

score = min(hard, K) * 140
if hard < K:
    score += min(K - hard, easy) * 100
print(score)