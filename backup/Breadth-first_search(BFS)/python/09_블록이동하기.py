# 이것이 취업을 위한 코딩테스트다
# https://school.programmers.co.kr/learn/courses/30/lessons/60063
# 2

from collections import deque


def get_next_pos(pos, board):
    next_pos = []
    pos = list(pos)
    x1, y1, x2, y2 = pos[0][0], pos[0][1], pos[1][0], pos[1][1]

    mx = [-1, 1, 0, 0]
    my = [0, 0, -1, 1]
    for i in range(4):
        nx1, ny1, nx2, ny2 = x1 + mx[i], y1 + my[i], x2 + mx[i], y2 + my[i]
        if board[nx1][ny1] == 0 and board[nx2][ny2] == 0:
            next_pos.append({(nx1, ny1), (nx2, ny2)})
    if x1 == x2:
        for i in [-1, 1]:
            if board[x1 + i][y1] == 0 and board[x2 + i][y2] == 0:
                next_pos.append({(x1, y1), (x1 + i, y1)})
                next_pos.append({(x2, y2), (x2 + i, y2)})
    elif y1 == y2:
        for i in [-1, 1]:
            if board[x1][y1 + i] == 0 and board[x2][y2 + i] == 0:
                next_pos.append({(x1, y1), (x1, y1 + i)})
                next_pos.append({(x2, y2), (x2, y2 + i)})
    return next_pos


def solution(board):
    N = len(board)
    new_board = [[1] * (N + 2) for _ in range(N + 2)]
    for i in range(N):
        for j in range(N):
            new_board[i + 1][j + 1] = board[i][j]

    q = deque()
    pos = {(1, 1), (1, 2)}
    q.append((pos, 0))
    visited = []
    visited.append(pos)
    while q:
        pos, cost = q.popleft()
        if (N, N) in pos:
            return cost

        for next_pos in get_next_pos(pos, new_board):
            if next_pos not in visited:
                q.append((next_pos, cost + 1))
                visited.append(next_pos)
    return 0
