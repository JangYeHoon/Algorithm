# 


N, M = map(int, input().split())
A = [list(map(int, input())) for _ in range(N)]
B = [list(map(int, input())) for _ in range(N)]

def flip(x, y, A):
    for i in range(3):
        for j in range(3):
            A[x + i][y + j] ^= 1

result = 0
for i in range(N - 2):
    for j in range(M - 2):
        if A[i][j] != B[i][j]:
            result += 1
            flip(i, j, A)
print(result if A == B else -1)