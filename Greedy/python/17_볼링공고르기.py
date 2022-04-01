# 이것이 취업을 위한 코딩테스트다 315p
# 1

N, M = map(int, input().split())
bolling = list(map(int, input().split()))
weight = [0] * 11

for b in bolling:
    weight[b] += 1

result = 0
for i in range(1, M + 1):
    N -= weight[i]
    result += weight[i] * N
print(result)