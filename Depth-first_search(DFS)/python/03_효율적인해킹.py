# fast campus 강의
# https://www.acmicpc.net/problem/1325
# 1

import sys
sys.setrecursionlimit(100000)

n, m = map(int, input().split())
matrix = [[] for _ in range(n + 1)]
visited = [False] * (n + 1)
count = 0

for _ in range(m):
    a, b = map(int, input().split())
    matrix[b].append(a)

def dfs(v):
    global count
    visited[v] = True
    for e in matrix[v]:
        if not(visited[e]):
            count += 1
            dfs(e)

result = []
max_value = -1
for i in range(1, n + 1):
    visited = [False] * (n + 1)
    dfs(i)
    if count > max_value:
        result = [i]
        max_value = count
    elif count == max_value:
        result.append(i)
        max_value = count
    count = 0

for e in result:
    print(e, end=' ')