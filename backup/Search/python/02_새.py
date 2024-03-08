# fast campus 강의
# https://www.acmicpc.net/problem/1568
# 2

N = int(input())

index = 1
result = 0
while N > 0:
    if index > N:
        index = 1
    N -= index
    index += 1
    result += 1
print(result)