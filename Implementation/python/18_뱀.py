# 
# https://www.acmicpc.net/problem/3190
# 

from collections import deque

N, K = int(input()), int(input())
board = [[0] * (N + 1) for _ in range(N + 1)]
for i in range(K):
    x, y = map(int, input().split())
    board[x][y] = 1
L = int(input())
direction_list = []
for i in range(L):
    direction = list(input().split())
    direction_list.append((int(direction[0]), direction[1]))

direction = 0
board[1][1] = 2
snake = deque()
snake.append((1, 1))
second = 1
mx, my = [0, 1, 0, -1], [1, 0, -1, 0]

while (1):
    x, y = snake.pop()
    nx, ny = x + mx[direction], y + my[direction]
    if nx < 1 or nx > N or ny < 1 or ny > N or board[nx][ny] == 2:
        break
    board[nx][ny] = 2
    snake.append((x, y))
    snake.append((nx, ny))
    if board[nx][ny] == 0:
        x, y = snake.popleft()
        board[x][y] = 0

    second += 1
    if len(direction_list) > 0:
        if second == direction_list[0][0]:
            if direction_list[0][1] == 'D':
                direction += 1
                if direction == 4: direction = 0                
            else:
                direction -= 1
                if direction == -1: direction = 3
            direction_list.pop(0)
print(second)