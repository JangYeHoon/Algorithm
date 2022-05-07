# fast campus 강의
# https://www.acmicpc.net/problem/1939
# 2

from collections import deque

n, m = map(int, input().split(' '))
matrix = [[] for _ in range(n + 1)]

def bfs(weight):
    queue = deque()
    queue.append(start_node)
    visited = [False] * (n + 1)
    visited[start_node] = True
    while queue:
        a = queue.popleft()
        for b, c in matrix[a]:
            if not visited[b] and c >= weight:
                visited[b] = True
                queue.append(b)
    return visited[end_node]

start = 987654321
end = 0
for _ in range(m):
    a, b, c = map(int, input().split(' '))
    matrix[a].append((b, c))
    matrix[b].append((a, c))
    start = min(start, c)
    end = max(end, c)

start_node, end_node = map(int, input().split(' '))
result = 0
while start <= end:
    mid = (start + end) // 2
    if bfs(mid):
        start = mid + 1
        result = mid
    else:
        end = mid - 1
print(result)