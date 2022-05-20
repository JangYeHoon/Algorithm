# fast campus 강의
# https://www.acmicpc.net/problem/17406
# 2

from copy import deepcopy

N, M, K = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]
Q = [tuple(map(int, input().split())) for _ in range(K)]
dx, dy = [1, 0, -1, 0], [0, -1, 0, 1]
result = 99999

def find_min_value(arr):
    return min([sum(i) for i in arr])

def convert(arr, qry):
    r, c, s = qry
    r, c = r - 1, c - 1
    new_arr = deepcopy(arr)
    for i in range(1, s + 1):
        mx, my = r - i, c + i
        for w in range(4):
            for d in range(i * 2):
                m_mx, m_my = mx + dx[w], my + dy[w]
                new_arr[m_mx][m_my] = arr[mx][my]
                mx, my = m_mx, m_my
    return new_arr

def dfs(arr, check):
    global result
    if sum(check) == K:
        result = min(result, find_min_value(arr))
        return
    for i in range(K):
        if check[i]:
            continue
        new_arr = convert(arr, Q[i])
        check[i] = 1
        dfs(new_arr, check)
        check[i] = 0

dfs(A, [0 for i in range(K)])
print(result)