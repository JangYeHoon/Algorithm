# 이것이 취업을 위한 코딩테스트다
# 1

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]


def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


n, m = map(int, input().split())
parent = [0] * (n + 1)

for i in range(1, n + 1):
    parent[i] = i

for i in range(n):
    list_tmp = list(map(int, input().split()))
    for j in range(n):
        if list_tmp[j] == 1:
            union_parent(parent, i + 1, j + 1)

visite_nodes = list(map(int, input().split()))
result = True
for i in range(m - 1):
    if find_parent(parent, visite_nodes[i]) != find_parent(parent, visited_nodes[i + 1]):
        result = False

if result:
    print("YES")
else:
    print("NO")
