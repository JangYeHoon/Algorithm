# fast campus 강의
# https://www.acmicpc.net/problem/2747
# 2

n = int(input())

# 재귀 풀이


def fibo(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return fibo(n - 1) + fibo(n - 2)


print(fibo(n))

# 반복 풀이
d = [0] * 100

d[1] = 1
d[2] = 1

for i in range(3, n + 1):
    d[i] = d[i - 1] + d[i - 2]

print(d[n])
