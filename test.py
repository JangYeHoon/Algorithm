# 

c = [0, 0, 0]
m = [0, 0, 0]
for i in range(3):
    c[i], m[i] = map(int, input().split())

for i in range(1, 101):
    p, q = (i - 1) % 3, i % 3
    m[q], m[p] = min(c[q], m[p] + m[q]), max(m[p] + m[q] - c[q], 0)

for i in range(3):
    print(m[i])