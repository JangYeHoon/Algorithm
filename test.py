# 보너스점수, MixingMilk

def candy_plus(C, N):
    for i in range(N):
        if C[i] % 2 != 0:
            C[i] += 1

def candy_chk(C, N):
    tmp = C[0]
    for i in C:
        if i != tmp:
            return False
    return True

for _ in range(int(input())):
    N = int(input())
    C = list(map(int, input().split()))
    candy_plus(C, N)

    result = 0
    while not(candy_chk(C, N)):
        tmpC = [i for i in C]
        for i in range(1, N + 1):
            C[i % N] = tmpC[i - 1] / 2 + C[i % N] / 2
        candy_plus(C, N)
        result += 1
    print(result)