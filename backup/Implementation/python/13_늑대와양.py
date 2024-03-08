# fast campus 강의
# https://www.acmicpc.net/problem/16956
# 2

R, C = map(int, input().split())
matrix = [list(input()) for i in range(R)]
dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]

check = False
for i in range(R):
    for j in range(C):
        if matrix[i][j] == 'W':
            for k in range(4):
                mx, my = i + dx[k], j + dy[k]
                if mx < 0 or mx == R or my < 0 or my == C:
                    continue
                if matrix[mx][my] == 'S':
                    check = True

if check:
    print(0)
else:
    print(1)
    for i in range(R):
        for j in range(C):
            if matrix[i][j] not in 'WS':
                matrix[i][j] = 'D'
    for i in matrix:
        print(''.join(i))