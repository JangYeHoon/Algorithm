# https://school.programmers.co.kr/learn/courses/30/lessons/120866

def solution(board):
    answer = 0
    n = len(board)
    mx = [1, -1, 0, 0, -1, -1, 1, 1]
    my = [0, 0, 1, -1, -1, 1, -1, 1]
    new_board = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if board[i][j] == 1:
                new_board[i][j] = 1
                for k in range(8):
                    nx = i + mx[k]
                    ny = j + my[k]
                    if nx >= 0 and nx < n and ny >= 0 and ny < n:
                        new_board[nx][ny] = 1

    cnt = 0
    for i in range(n):
        for j in range(n):
            if new_board[i][j] == 1:
                cnt += 1
    return n * n - cnt