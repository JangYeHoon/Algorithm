# fast campus 강의
# https://www.acmicpc.net/problem/1697
# 1

from collections import deque

n, k = map(int, input().split())
visited = [0] * 100001

def bfs():
    q = deque([n])
    while q:
        x = q.popleft()
        if x == k:
            return visited[x]
        for next in (x - 1, x + 1, x * 2):
            if 0 <= next < 100001 and visited[next] == 0:
                visited[next] = visited[x] + 1
                q.append(next)

print(bfs())