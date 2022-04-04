# 

N, M = map(int, input().split())
arr = list(map(int, input().split()))
weight = [0] * 11

for a in arr:
    weight[a] += 1

result = 0
for i in range(1, M + 1):
    N -= weight[i]      # A가 고른 무게
    result += weight[i] * N     # A가 고른 무게를 제외해서 B가 고를 수 있는 경우의 수
print(result)