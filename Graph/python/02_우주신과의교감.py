# fast campus 강의
# https://www.acmicpc.net/problem/1774
# 2

import math

def get_distance(p1, p2):
    x = p1[0] - p2[0]
    y = p1[1] - p2[1]
    return math.sqrt((x * x) + (y * y))

def find_parent(x):
    if parent[x] != x:
        parent[x] = find_parent(parent[x])
    return parent[x]

def union_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)
    if a < b:
        parent[a] = b
    else:
        parent[b] = a

N, M = map(int, input().split())
parent = [0] * (N + 1)
locations = []
edges = []

for _ in range(N):
    x, y = map(int, input().split())
    locations.append((x, y))

length = len(locations)
for i in range(length - 1):
    for j in range(i + 1, length):
        edges.append((get_distance(locations[i], locations[j]), i + 1, j + 1))
edges.sort()

for i in range(1, N + 1):
    parent[i] = i

for _ in range(M):
    a, b = map(int, input().split())
    union_parent(a, b)

result = 0
for cost, a, b in edges:
    if find_parent(a) != find_parent(b):
        union_parent(a, b)
        result += cost
print("%0.2f" % result)