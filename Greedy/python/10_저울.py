# fast campus 강의
# https://www.acmicpc.net/problem/2437
# 1

N, A = int(input()), sorted(list(map(int, input().split())))

# 만들 수 있는 최저
result = 0

for i in A:
    if i <= result + 1:
        result += i
    else:
        break

print(result + 1)