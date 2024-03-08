# 이것이 취업을 위한 코딩테스트다
# https://www.acmicpc.net/problem/1932
# 1

n = int(input())
matrix = []
for _ in range(n):
    lst = list(map(int, input().split()))
    matrix.append(lst)

for i in range(1, n):
    for j in range(i + 1):
        if j == 0:
            up_left = 0
        else:
            up_left = matrix[i - 1][j - 1]
        if i == j:
            up = 0
        else:
            up = matrix[i - 1][j]
        matrix[i][j] = matrix[i][j] + max(up, up_left)

print(max(matrix[n - 1]))
