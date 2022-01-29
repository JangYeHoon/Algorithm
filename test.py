# 괄호변환(dfs), 연산자끼워넣기(dfs), 감시피하기(dfs), 행복(Implementation)

from itertools import combinations

N = int(input())
matrix = [['X'] * N for _ in range(N)]
space = []
teacher = []
mx, my = [-1, 1, 0, 0], [0, 0, -1, 1]

def dfs(x, y, i):
    if matrix[x][y] == 'S':
        return True
    if matrix[x][y] == 'O':
        return False
    nx = x + mx[i]
    ny = y + my[i]
    if nx >= 0 and nx < N and ny >= 0 and ny < N:
        return dfs(nx, ny, i)
    else:
        return False

def check():
    for x, y in teacher:
        for i in range(4):
            if dfs(x, y, i):
                return False
    return True

for i in range(N):
    temp_list = list(input().split())
    for j in range(N):
        matrix[i][j] = temp_list[j]
        if matrix[i][j] == 'X':
            space.append((i, j))
        elif matrix[i][j] == 'T':
            teacher.append((i, j))
chk = False
for s in combinations(space, 3):
    for x, y in s:
        matrix[x][y] = 'O'
    if check():
        chk = True
        print("YES")
        break
    for x, y in s:
        matrix[x][y] = 'X'
if not(chk):
    print("NO")