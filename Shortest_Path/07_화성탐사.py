# 이것이 취업을 위한 코딩테스트다
# 0

import heapq

mx, my = [1, 0, -1, 0], [0, 1, 0, -1]


def dijkstra():
    q = [(matrix[0][0], 0, 0)]

    while q:
        d, px, py = heapq.heappop(q)

        if dist[px][py] < d:
            continue
        for i in range(4):
            nx = px + mx[i]
            ny = py + my[i]

            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue

            cost = d + matrix[nx][ny]
            if cost < dist[nx][ny]:
                heapq.heappush(q, (cost, nx, ny))
                dist[nx][ny] = cost


for _ in range(int(input())):
    n = int(input())
    matrix = [list(map(int, input().split())) for _ in range(n)]
    dist = [[1e9] * n for _ in range(n)]
    dijkstra()
    print(dist[n - 1][n - 1])
