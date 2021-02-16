n, m = map(int, input().split(' '))

matrix = []
for i in range(n):
    matrix.append(input())

n_row = [0] * n
m_col = [0] * m
for i in range(n):
    for j in range(m):
        if matrix[i][j] == 'X':
            n_row[i] = 1
            m_col[j] = 1

n_num = 0
m_num = 0
for i in range(n):
    if n_row[i] == 0:
        n_num += 1

for i in range(m):
    if m_col[i] == 0:
        m_num += 1

print(max(n_num, m_num))