# fast campus 강의
# https://www.acmicpc.net/problem/1236
# 1

n, m = map(int, input().split(' '))

matrix = []
for i in range(n):
    matrix.append(input())

row = [0] * n
col = [0] * m
for i in range(n):
    for j in range(m):
        if matrix[i][j] == 'X':
            row[i] = 1
            col[j] = 1

row_count = 0
for i in range(n):
    if row[i] == 0:
        row_count += 1

column_count = 0
for j in range(m):
    if col[j] == 0:
        column_count += 1

print(max(row_count, column_count))