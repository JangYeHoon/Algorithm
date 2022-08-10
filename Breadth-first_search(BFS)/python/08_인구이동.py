# 이것이 취업을 위한 코딩테스트다 353
# https://www.acmicpc.net/problem/16234
# 1

from collections import deque
from copy import deepcopy

mx = [1, 0, -1, 0]
my = [0, 1, 0, -1]


def bfs(x, y):
    q = deque([x, y])
    ret = []
    person_sum = 0
    country_cnt = 0

    while q:
        px = q.popleft()
        py = q.popleft()

        for i in range(4):
            nx = px + mx[i]
            ny = py + my[i]

            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue

            diff_cnt = abs(matrix[px][py] - matrix[nx][ny])
            if L <= diff_cnt and diff_cnt <= R and not(visited[nx][ny]):
                if not visited[x][y]:
                    visited[x][y] = True
                    country_cnt += 1
                    person_sum += matrix[x][y]
                    ret.append([x, y])
                visited[nx][ny] = True
                person_sum += matrix[nx][ny]
                country_cnt += 1
                ret.append([nx, ny])
                q.append(nx)
                q.append(ny)
    return person_sum, country_cnt, ret


N, L, R = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(N)]

result = 0
while True:
    visited = [[False] * N for _ in range(N)]
    new_matrix = deepcopy(matrix)
    for i in range(N):
        for j in range(N):
            if not (visited[i][j]):
                person_sum, country_cnt, move = bfs(i, j)
                for m in move:
                    new_matrix[m[0]][m[1]] = person_sum // country_cnt
    if new_matrix == matrix:
        break
    matrix = new_matrix
    result += 1
print(result)
