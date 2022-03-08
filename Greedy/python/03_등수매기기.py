# fast campus 강의
# https://www.acmicpc.net/problem/2012
# 1

N = int(input())
arr = []
for _ in range(N):
    arr.append(int(input()))

arr.sort()

result = 0
for i in range(N):
    result += abs((i + 1) - arr[i])
print(result)