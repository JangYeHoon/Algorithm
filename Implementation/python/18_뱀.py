# 
# https://www.acmicpc.net/problem/3190
# 1

N, K = int(input()), int(input())
board = [[0] * (N + 1) for _ in range(N + 1)]
mx, my = [0, 1, 0, -1], [1, 0, -1, 0]
direction_list = []

for _ in range(K):
    x, y = map(int, input().split())
    board[x][y] = 1
L = int(input())
for i in range(L):
    s, d = input().split()
    direction_list.append((int(s), d))


def turn (direction, c):
    if c == 'L':
        direction = (direction - 1) % 4
    else:
        direction = (direction + 1) % 4
    return direction

def simulate():
    board[1][1] = 2
    direction = 0
    second = 0
    snake = [(1, 1)]
    hx, hy = 1, 1
    turn_index = 0

    while (1):
        nx, ny = hx + mx[direction], hy + my[direction]
        if 1 <= nx and nx <= N and 1 <= ny and ny <= N and board[nx][ny] != 2:
            if board[nx][ny] == 0:
                tx, ty = snake.pop(0)
                board[tx][ty] = 0
            board[nx][ny] = 2
            snake.append((nx, ny))
        else:
            second += 1
            break
        hx, hy = nx, ny
        second += 1
        if turn_index < L and direction_list[turn_index][0] == second:
            direction = turn(direction, direction_list[turn_index][1])
            turn_index += 1
    return second
print(simulate())