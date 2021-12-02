# 키로거, SHA-265(python), 수찾기

N = int(input())
A = {i : 1 for i in list(map(int, input().split()))}
M = int(input())

for i in range(M):
    print(A.get(i, 0))