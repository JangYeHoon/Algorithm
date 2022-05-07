# fast campus 강의
# https://www.acmicpc.net/problem/2250
# 2

class Node:
    def __init__(self, value, left, right):
        self.parent = -1
        self.value = value
        self.left = left
        self.right = right

def inorder(node, level):
    global level_width, cnt
    level_width = max(level_width, level)
    if node.left != -1:
        inorder(tree[node.left], level + 1)
    level_min[level] = min(level_min[level], cnt)
    level_max[level] = max(level_max[level], cnt)
    cnt += 1
    if node.right != -1:
        inorder(tree[node.right], level + 1)

N = int(input())
tree = {}
level_min = [N]
level_max = [0]
cnt = 0
level_width = 0

for i in range(1, N + 1):
    tree[i] = Node(i, -1, -1)
    level_min.append(N)
    level_max.append(0)

for _ in range(N):
    value, left, right = map(int, input().split())
    tree[value].left = left
    tree[value].right = right

    if left != -1:
        tree[left].parent = value
    if right != -1:
        tree[right].parent = value

for i in range(1, N + 1):
    if tree[i].parent == -1:
        root = i

inorder(tree[root], 1)
result_level, result_width = 0, 0
for i in range(1, N + 1):
    width = level_max[i] - level_min[i] + 1
    if result_width < width:
        result_level = i
        result_width = width

print("{} {}".format(result_level, result_width))