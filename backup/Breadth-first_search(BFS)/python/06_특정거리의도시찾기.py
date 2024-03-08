# 이것이 취업을 위한 코딩테스트다 339p
# https://www.acmicpc.net/problem/18352
# 2

from collections import deque
import sys

def bfs(n):
    q = deque([n])
    distance[n] = 0

    while q:
        px = q.popleft()
        for nx in matrix[px]:
            if distance[nx] == -1:
                q.append(nx)
                distance[nx] = distance[px] + 1

N, M, K, X = map(int, sys.stdin.readline().split())
matrix = [[] for i in range(N + 1)]
distance = [-1] *(N + 1)

for _ in range(M):
    x, y = map(int, sys.stdin.readline().split())
    matrix[x].append(y)

bfs(X)

chk = False
for i in range(N + 1):
    if distance[i] == K:
        chk = True
        print(i)

if not(chk):
    print(-1)