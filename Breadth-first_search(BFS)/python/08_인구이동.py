# 이것이 취업을 위한 코딩테스트다 353
# https://www.acmicpc.net/problem/16234
# 2

from collections import deque
from copy import deepcopy

mx = [1, 0, -1, 0]
my = [0, 1, 0, -1]


def bfs(x, y, index):
    united = []
    united.append((x, y))
    q = deque()
    q.append((x, y))
    union[x][y] = index
    person_sum = matrix[x][y]
    country_cnt = 1

    while q:
        px, py = q.popleft()

        for i in range(4):
            nx = px + mx[i]
            ny = py + my[i]

            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue

            diff_cnt = abs(matrix[px][py] - matrix[nx][ny])
            if L <= diff_cnt and diff_cnt <= R and union[nx][ny] == -1:
                union[nx][ny] = index
                united.append((nx, ny))
                person_sum += matrix[nx][ny]
                country_cnt += 1
                q.append((nx, ny))
    for i, j in united:
        matrix[i][j] = person_sum // country_cnt


N, L, R = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(N)]

result = 0
while True:
    union = [[-1] * N for _ in range(N)]
    index = 0
    for i in range(N):
        for j in range(N):
            if union[i][j] == -1:
                bfs(i, j, index)
                index += 1
    if index == N * N:
        break
    result += 1
print(result)
