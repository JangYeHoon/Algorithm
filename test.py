# 꽃길, 늑대와양

R, C = map(int, input().split())
matrix = [list(input()) for _ in range(R)]
mx, my = [-1, 1, 0, 0], [0, 0, -1, 1]

result_chk = True
for i in range(R):
    for j in range(C):
        if matrix[i][j] == 'W':
            for k in range(4):
                nx = i + mx[k]
                ny = j + my[k]

                if nx < 0 or nx >= R or ny < 0 or ny >= C:
                    continue
                if matrix[nx][ny] == 'S':
                    result_chk = False

if result_chk:
    print(1)
    for i in range(R):
        for j in range(C):
            if matrix[i][j] not in 'SW':
                matrix[i][j] = 'D'
    for m in matrix:
        print(''.join(m))
else:
    print(0)