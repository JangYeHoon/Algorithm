N = int(input())
A = {i : 1 for i in list(map(int, input().split()))}
M = int(input())

for i in list(map(int, input().split())):
    print(A.get(i, 0))