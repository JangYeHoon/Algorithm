# 

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
        number[x] += number[y]

for _ in range(int(input())):
    F = int(input())
    parent = {}
    number = {}

    for _ in range(F):
        f1, f2 = input().split()

        if f1 not in parent:
            parent[f1] = f1
            number[f1] = 1
        if f2 not in parent:
            parent[f2] = f2
            number[f2] = 1
        
        unionParent(f1, f2)
        print(number[findParent(f1)])