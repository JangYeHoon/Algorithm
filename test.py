# 효율적인해킹(bfs), 특정 거리의 도시 찾기(bfs), 경쟁적 전염(bfs), 바이러스(dfs), 유기농배추(dfs), 효율적인해킹(dfs), MooyoMooyo(dfs), 2048(Easy)(dfs)

from copy import deepcopy

N = int(input())
Board = [list(map(int, input().split())) for _ in range(N)]

def rotate90(n, b):
    nb = deepcopy(b)
    for i in range(N):
        for j in range(N):
            nb[j][N - i - 1] = b[i][j]
    return nb

def convert(n, lst):
    new_list = [i for i in lst if i != 0]
    for i in range(1, len(new_list)):
        if new_list[i - 1] == new_list[i]:
            new_list[i - 1] *= 2
            new_list[i] = 0
    new_list = [i for i in new_list if i != 0]
    return new_list + [0] * (N - len(new_list))

def dfs(n, b, cnt):
    ret = max([max(i) for i in b])
    if cnt == 0:
        return ret
    
    for _ in range(4):
        x = [convert(N, lst) for lst in b]
        if x != b:
            ret = max(ret, dfs(n, x, cnt - 1))
        b = rotate90(N, b)
    return ret

print(dfs(N, Board, 5))