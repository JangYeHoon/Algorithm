# 이것이 취업을 위한 코딩테스트다
# 1

import heapq

mx, my = [1, 0, -1, 0], [0, 1, 0, -1]

for _ in range(int(input())):
    n = int(input())
    matrix = [list(map(int, input().split())) for _ in range(n)]
    distance = [[1e9] * n for _ in range(n)]

    q = [(matrix[0][0], 0, 0)]
    distance[0][0] = matrix[0][0]

    while q:
        dist, px, py = heapq.heappop(q)

        if distance[px][py] < dist:
            continue

        for i in range(4):
            nx = px + mx[i]
            ny = py + my[i]

            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue

            cost = dist + matrix[nx][ny]
            if cost < distance[nx][ny]:
                distance[nx][ny] = cost
                heapq.heappush(q, (cost, nx, ny))
    print(distance[n - 1][n - 1])