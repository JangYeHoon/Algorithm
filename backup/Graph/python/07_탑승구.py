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

G = int(input())
P = int(input())
parent = [0] * (G + 1)

for i in range(G + 1):
    parent[i] = i

result = 0
for i in range(P):
    root_node = find_parent(parent, int(input()))
    if root_node == 0:
        break
    union_parent(parent, root_node, root_node - 1)
    result += 1
print(result)