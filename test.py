# 

N, L, K = map(int, input().split())
easy, hard = 0, 0
for _ in range(N):
    sub1, sub2 = map(int, input().split())
    if sub2 <= L:
        hard += 1
    elif sub1 <= L:
        easy += 1

result = min(hard, K) * 140
if hard < K:
    result += min(easy, K - hard) * 100
print(result)