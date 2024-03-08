# 이것이 취업을 위한 코딩테스트다 298p
# 2

N, M = map(int, input().split())
parent = [0] * (N + 1)
for i in range(1, N + 1):
    parent[i] = i

def find_parent(x):
    if parent[x] != x:
        parent[x] = find_parent(parent[x])
    return parent[x]

def union_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

for _ in range(M):
    oper, a, b = map(int, input().split())
    if oper == 0:
        union_parent(a, b)
    else:
        if find_parent(a) == find_parent(b):
            print("YES")
        else:
            print("NO")