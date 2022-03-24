# 근우의다이어리, 저울, 행렬

N, M = map(int, input().split())
A = []
B = []
for _ in range(N):
    lst = list(map(int, input()))
    A.append(lst)
for _ in range(N):
    lst = list(map(int, input()))
    B.append(lst)

result = 0
for i in range(N - 2):
    for j in range(M - 2):
        if A[i][j] != B[i][j]:
            result += 1
            for x in range(i, i + 3):
                for y in range(j, j + 3):
                    A[x][y] = 0 if A[x][y] == 1 else 1
if A == B:
    print(result)
else:
    print(-1)