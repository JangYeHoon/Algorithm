# 이것이 취업을 위한 코딩테스트다 300p
# https://www.acmicpc.net/problem/1647
# 1

def find_parent(a):
    if parent[a] != a:
        parent[a] = find_parent(parent[a])
    return parent[a]

def union_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)
    if a < b:
        parent[a] = b
    else:
        parent[b] = a

N, M = map(int, input().split())
parent = [0] * (N + 1)

for i in range(1, N + 1):
    parent[i] = i

edges = []
for _ in range(M):
    a, b, c = map(int, input().split())
    edges.append((c, a, b))
edges.sort()

max_cost = 0
result = 0
for edge in edges:
    cost, a, b = edge
    if find_parent(a) != find_parent(b):
        union_parent(a, b)
        result += cost
        max_cost = max(max_cost, cost)

print(result - max_cost)