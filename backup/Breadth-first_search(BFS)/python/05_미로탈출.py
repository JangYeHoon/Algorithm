# 이것이 취업을 위한 코딩테스트다 152p
# https://www.acmicpc.net/problem/2178
# 2

from collections import deque

mx, my = [-1, 1, 0, 0], [0, 0, -1, 1]

def bfs():
    q = deque()
    q.append((0, 0))

    while q:
        px, py = q.popleft()
        if px == N - 1 and py == M - 1:
            return matrix[px][py]

        for i in range(4):
            nx = px + mx[i]
            ny = py + my[i]

            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                continue
            if matrix[nx][ny] == 1:
                matrix[nx][ny] = matrix[px][py] + 1
                q.append((nx, ny))

N, M = map(int, input().split())
matrix = [list(map(int, input())) for _ in range(N)]

print(bfs())