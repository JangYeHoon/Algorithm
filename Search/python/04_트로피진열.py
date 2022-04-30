# fast campus 강의
# https://www.acmicpc.net/problem/1668
# 2

def ascending(trophy):
    now = trophy[0]
    result = 1
    for i in range(1, len(trophy)):
        if now < trophy[i]:
            result += 1
            now = trophy[i]
    return result

N = int(input())
trophy = []

for _ in range(N):
    trophy.append(int(input()))

print(ascending(trophy))
trophy.reverse()
print(ascending(trophy))