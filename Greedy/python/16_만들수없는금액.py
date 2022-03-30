# 이것이 취업을 위한 코딩테스트다 314p
# 비슷한 문제 : https://www.acmicpc.net/problem/2437
# 1

N = int(input())
coin = sorted(list(map(int, input().split())))

result = 1
for c in coin:
    if result < c:
        break
    result += c
print(result)