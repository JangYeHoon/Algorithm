# fast campus 강의
# https://www.acmicpc.net/problem/9037
# 2

def candy_plus(C, N):
    for i in range(N):
        if C[i] % 2 != 0:
            C[i] += 1

def candy_chk(C, N):
    tmp = C[0]
    for i in range(N):
        if tmp != C[i]:
            return True
    return False

for _ in range(int(input())):
    N = int(input())
    C = list(map(int, input().split()))
    candy_plus(C, N)

    result = 0
    while candy_chk(C, N):
        tmpC = [i for i in C]
        for i in range(1, N + 1):
            C[i % N] = C[i % N] / 2 + tmpC[i - 1] / 2
        candy_plus(C, N)
        result += 1
    print(result)