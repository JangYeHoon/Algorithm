import math
import sys
input = sys.stdin.readline

def get_distance(p1, p2):
    a = p1[0] - p2[0]
    b = p1[1] - p2[1]
    return math.sqrt((a * a) + (b * b))

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if b < a:
        parent[b] = a
    else:
        parent[a] = b

def equal_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a == b:
        return True
    else:
        return False

n, m = map(int, input().split())
parent = {}
locations = []
edges = []

for _ in range(n):
    x, y = map(int, input().split())
    locations.append((x, y))

length = len(locations)

for i in range(length - 1):
    for j in range(i + 1, length):
        edges.append((i + 1, j + 1, get_distance(locations[i], locations[j])))

for i in range(n + 1):
    parent[i] = i

edges.sort(key=lambda data:data[2])

for _ in range(m):
    x, y = map(int, input().split())
    union_parent(parent, x, y)

result = 0
for a, b, cost in edges:
    if not equal_parent(parent, a, b):
        union_parent(parent, a, b)
        result += cost

print("%0.2f" % result)