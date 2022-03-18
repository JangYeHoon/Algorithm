# 센서, 도서관, 컵라면, APC

N, L, K = map(int, input().split())
easy, difficult = 0, 0
for _ in range(N):
    e, d = map(int, input().split())
    if d <= L:
        difficult += 1
    elif e <= L:
        easy += 1

result = min(difficult, K) * 140
if difficult < K:
    result += min(K - difficult, easy) * 100
print(result)