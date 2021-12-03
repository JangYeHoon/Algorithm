# 키로거, SHA-265(python), 수찾기, 친구네트워크

def findParent(x):
    if x == parent[x]:
        return x
    else:
        p = findParent(parent[x])
        parent[x] = p
        return parent[x]

def unionParent(x, y):
    x = findParent(x)
    y = findParent(y)

    if x != y:
        parent[y] = x
        network_count[x] += network_count[y]

for _ in range(int(input())):
    F = int(input())
    parent = {}
    network_count = {}

    for _ in range(F):
        x, y = input().split()

        if x not in parent:
            parent[x] = x
            network_count[x] = 1
        if y not in parent:
            parent[y] = y
            network_count[y] = 1

        unionParent(x, y)
        print(network_count[findParent(x)])