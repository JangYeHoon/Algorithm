def preorder(node):
    print(node, end='')
    if matrix[node][0] != '.':
        preorder(matrix[node][0])
    if matrix[node][1] != '.':
        preorder(matrix[node][1])

def inorder(node):
    if matrix[node][0] != '.':
        inorder(matrix[node][0])
    print(node, end='')
    if matrix[node][1] != '.':
        inorder(matrix[node][1])

def postorder(node):
    if matrix[node][0] != '.':
        postorder(matrix[node][0])
    if matrix[node][1] != '.':
        postorder(matrix[node][1])
    print(node, end='')

n = int(input())
matrix = {}
for _ in range(n):
    node, left, right = input().split(' ')
    matrix[node] = (left, right)
preorder('A')
print()
inorder('A')
print()
postorder('A')