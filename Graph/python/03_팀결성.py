# 이것이 취업을 위한 코딩테스트다 298p
# 1

def find_parent(a):
    if parent[a] != a:
        parent[a] = find_parent(parent[a])
    return parent[a]

def union_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)
    if a > b:
        parent[a] = b
    else:
        parent[b] = a

def compare_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)
    if a == b:
        return True
    else:
        return False

N, M = map(int, input().split())
parent = [0] * (N + 1)
for i in range(0, N + 1):
    parent[i] = i

for _ in range(M):
    oper, a, b = map(int, input().split())
    if oper == 0:
        union_parent(a, b)
    else:
        if (compare_parent(a, b)):
            print("YES")
        else:
            print("NO")