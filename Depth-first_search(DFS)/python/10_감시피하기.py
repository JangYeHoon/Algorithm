# 이것이 취업을 위한 코딩테스트다 351p
# https://www.acmicpc.net/problem/18428
# 1

from itertools import combinations
import sys
sys.setrecursionlimit(100000)

N = int(input())

matrix = [['X'] * N for _ in range(N)]
space = []
teacher = []
mx, my = [-1, 1, 0, 0], [0, 0, -1, 1]

for i in range(N):
    temp = list(input().split())
    for j in range(N):
        matrix[i][j] = temp[j]
        if matrix[i][j] == 'X':
            space.append((i, j))
        elif matrix[i][j] == 'T':
            teacher.append((i, j))

def dfs(x, y, idx):
    if matrix[x][y] == 'O':
        return False
    elif matrix[x][y] == 'S':
        return True
    nx = x + mx[idx]
    ny = y + my[idx]

    if nx >= 0 and nx < N and ny >= 0 and ny < N:
        return dfs(nx, ny, idx)

def check():
    for x, y in teacher:
        for i in range(4):
            if dfs(x, y, i):
                return False
    return True

result = False
for s in combinations(space, 3):
    for x, y in s:
        matrix[x][y] = 'O'
    if check():
        print("YES")
        result = True
        break
    for x, y in s:
        matrix[x][y] = 'X'
if not(result):
    print("NO")