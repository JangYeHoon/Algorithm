# 기둥과보, 치킨배달

N = int(input())
K = int(input())
matrix = [[0] * (N + 1) for _ in range(N + 1)]
for i in range(K):
    x, y = map(int, input().split())
    matrix[x][y] = 1
L = int(input())
direction_list = []
for i in range(L):
    x, c = input().split()
    direction_list.append((int(x), c))

def direction_turn(direction, turn):
    if turn == 'L': direction = (direction - 1) % 4
    else: direction = (direction + 1) % 4
    return direction

def solution():
    snake = [(1, 1)]
    second = 0
    direction = 0
    direction_idx = 0
    x, y = 1, 1
    matrix[x][y] = 2
    mx, my = [0, 1, 0, -1], [1, 0, -1, 0]
    while 1:
        nx, ny = x + mx[direction], y + my[direction]
        if nx > 0 and nx <= N and ny > 0 and ny <= N and matrix[nx][ny] != 2:
            if matrix[nx][ny] == 0:
                px, py = snake.pop(0)
                matrix[px][py] = 0
            matrix[nx][ny] = 2
            snake.append((nx, ny))
            x, y = nx, ny
        else:
            second += 1
            break
        second += 1
        if direction_idx < L and direction_list[direction_idx][0] == second:
            direction = direction_turn(direction, direction_list[direction_idx][1])
            direction_idx += 1
    return second

print(solution())