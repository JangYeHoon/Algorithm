# fast campus 강의
# https://www.acmicpc.net/problem/14620
# 1

N = int(input())
prise_matrix = [list(map(int, input().split())) for i in range(N)]
dx, dy = [0, 1, -1, 0, 0], [0, 0, 0, 1, -1]

def count(lst):
    ret = 0
    flower_list = []
    for flower in lst:
        x = flower // N
        y = flower % N
        if x == 0 or x == N - 1 or y == 0 or y == N - 1:
            return 99999
        for i in range(5):
            flower_list.append((x + dx[i], y + dy[i]))
            ret += prise_matrix[x + dx[i]][y + dy[i]]
    if len(set(flower_list)) != 15:
        return 99999
    return ret

result = 99999
for i in range(N * N):
    for j in range(i + 1, N * N):
        for k in range(j + 1, N * N):
            result = min(result, count([i, j, k]))

print(result)