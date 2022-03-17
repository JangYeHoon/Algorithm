# fast campus 강의
# https://www.acmicpc.net/problem/1781
# 1

import heapq

n = int(input())

arr = []
for _ in range(n):
    dead, cup = map(int, input().split(' '))
    arr.append((dead, cup))

arr.sort()
print(arr)
result = []
for deadline, cup in arr:
    heapq.heappush(result, cup)
    if len(result) > deadline:
        heapq.heappop(result)

print(sum(result))