# fast campus 강의
# https://www.acmicpc.net/problem/10539
# 2

n, num_list = int(input()), list(map(int, input().split()))

result = [num_list[0]]
for i in range(1, n):
    result.append(num_list[i] * (i + 1) - sum(result))

for i in result:
    print(i, end=' ')