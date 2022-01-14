# fast campus 강의
# https://www.acmicpc.net/problem/12100
# 1

from copy import deepcopy

N = int(input())
board = [list(map(int, input().split())) for i in range(N)]

def rotate90(board, N):
    rotate_board = deepcopy(board)
    for i in range(N):
        for j in range(N):
            rotate_board[j][N - i - 1] = board[i][j]
    return rotate_board

def convert(lst, N):
    new_list = [i for i in lst if i != 0]
    for i in range(1, len(new_list)):
        if new_list[i - 1] == new_list[i]:
            new_list[i - 1] *= 2
            new_list[i] = 0
    new_list = [i for i in new_list if i != 0]
    return new_list + [0] * (N - len(new_list))

def dfs(N, board, count):
    ret = max([max(i) for i in board])
    if count == 0:
        return ret
    for _ in range(4):
        X = [convert(lst, N) for lst in board]
        if X != board:
            ret = max(ret, dfs(N, X, count - 1))
        board = rotate90(board, N)
    return ret

print(dfs(N, board, 5))