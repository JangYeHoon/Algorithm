r, c = map(int, input().split(' '))
arr = [[0] * c for _ in range(r)]

for i in range(r):
    s = input()
    for j in range(c):
        arr[i][j] = s[j]
