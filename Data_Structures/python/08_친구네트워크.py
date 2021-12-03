# fast campus 강의
# https://www.acmicpc.net/problem/4195
# 1

def find(x):
    if x == parent[x]:
        return x
    else:
        p = find(parent[x])
        parent[x] = p
        return parent[x]

def union(x, y):
    x = find(x)
    y = find(y)

    if x != y:
        parent[y] = x
        network_count[x] += network_count[y]

test_case = int(input())

for _ in range(test_case):
    parent = {}
    network_count = {}

    f = int(input())

    for _ in range(f):
        x, y = input().split(' ')

        if x not in parent:
            parent[x] = x
            network_count[x] = 1
        if y not in parent:
            parent[y] = y
            network_count[y] = 1
        
        union(x, y)
        print(network_count[find(x)])