# fast campus 강의
# https://www.acmicpc.net/problem/1781
# 2

import heapq

N = int(input())
arr = []
for i in range(N):
    deadline, cup = map(int, input().split())
    arr.append((deadline, cup))
arr.sort()

result = []
for deadline, cup in arr:
    heapq.heappush(result, cup)
    if len(result) > deadline:
        heapq.heappop(result)

print(sum(result))