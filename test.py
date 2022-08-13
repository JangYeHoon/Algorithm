# 암호만들기, 인구이동

mx = [1, 0, -1, 0]
my = [0, 1, 0, -1]


def bfs(x, y):
    global result
    q = set()
    q.add((x, y, array[x][y]))

    while q:
        px, py, step = q.pop()
        result = max(result, len(step))

        for i in range(4):
            nx = px + mx[i]
            ny = py + my[i]

            if nx < 0 or nx >= R or ny < 0 or ny >= C:
                continue

            if array[nx][ny] not in step:
                q.add((nx, ny, step + array[nx][ny]))


R, C = map(int, input().split())
array = []
for _ in range(R):
    array.append(input())

result = 0
bfs(0, 0)
print(result)
