# fast campus 강의
# https://www.acmicpc.net/problem/1012
# 1
import sys
from collections import deque
sys.setrecursionlimit(10000)

T = int(input())
matrix = [[]]
visit = [[]]
dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]

def dfs(x, y):
    global matrix, visit
    visit[x][y] = True
    for i in range(4):
        mx, my = x + dx[i], y + dy[i]
        if matrix[mx][my] == 0 or visit[mx][my]:
            continue
        dfs(mx, my)

def bfs(x, y):
    q = deque([x, y])
    while q:
        px = q.popleft()
        py = q.popleft()
        if not visit[px][py]:
            visit[px][py] = True
            for i in range(4):
                mx = px + dx[i]
                my = py + dy[i]
                if matrix[mx][my] == 0 or visit[mx][my]:
                    continue
                q.append(mx)
                q.append(my)

def process():
    global matrix, visit
    M, N, K = map(int, input().split())
    matrix = [[0 for i in range(M + 2)] for _ in range(N + 2)]
    visit = [[False for i in range(M + 2)] for _ in range(N + 2)]
    for _ in range(K):
        x, y = map(int, input().split())
        matrix[y + 1][x + 1] = 1
    
    result = 0
    for i in range(1, N + 1):
        for j in range(1, M + 1):
            if matrix[i][j] == 0 or visit[i][j]:
                continue
            bfs(i, j)
            result += 1
    print(result)


for _ in range(T):
    process()