# 이것이 취업을 위한 코딩테스트다
# 2

N = int(input())
d = [0] * (N + 1)

d[1] = 1
d[2] = 3
for i in range(3, N + 1):
    d[i] = (d[i - 1] + d[i - 2] * 2) % 796796

print(d[N])