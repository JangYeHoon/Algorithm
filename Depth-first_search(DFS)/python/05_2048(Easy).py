# fast campus 강의
# https://www.acmicpc.net/problem/12100
# 2

#from copy import deepcopy

def rotate90(b):
    # new_board = deepcopy(b)
    new_board = [[0] * (N) for _ in range(N)]
    for i in range(N):
        for j in range(N):
            new_board[j][N - i - 1] = b[i][j]
    return new_board

def convert(b):
    new_list = [i for i in b if i != 0]
    for i in range(1, len(new_list)):
        if new_list[i - 1] == new_list[i]:
            new_list[i - 1] *= 2
            new_list[i] = 0
    new_list = [i for i in new_list if i != 0]
    return new_list + [0] * (N - len(new_list))

def dfs(b, cnt):
    ret = max(max(i) for i in b)
    if cnt == 5:
        return ret
    
    for _ in range(4):
        x = [convert(i) for i in b]
        if b != x:
            ret = max(ret, dfs(x, cnt + 1))
        b = rotate90(b)
    return ret

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
print(dfs(board, 0))