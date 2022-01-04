# 이것이 취업을 위한 코딩테스트다 152p
# https://www.acmicpc.net/problem/2178
# 1

from collections import deque

N, M = map(int, input().split())
matrix = []
mx = [-1, 1, 0, 0]
my = [0, 0, -1, 1]

for i in range(N):
    matrix.append(list(map(int, input())))

def bfs():
    q = deque()
    q.append((0, 0))
    while q:
        px, py = q.popleft()
        
        for i in range(4):
            nx = px + mx[i]
            ny = py + my[i]

            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                continue
            if not(matrix[nx][ny]):
                continue
            if matrix[nx][ny] == 1:
                matrix[nx][ny] = matrix[px][py] + 1
                q.append((nx, ny))
    return matrix[N - 1][M - 1]

print(bfs())