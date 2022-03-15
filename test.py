# 센서, 도서관

import heapq

N, M = map(int, input().split())
arr = list(map(int, input().split()))

minus_arr = []
plus_arr = []
largest = max(max(arr), -min(arr))
for x in arr:
    if x < 0:
        heapq.heappush(minus_arr, x)
    else:
        heapq.heappush(plus_arr, -x)

result = 0

while plus_arr:
    result += heapq.heappop(plus_arr)
    for _ in range(M - 1):
        if plus_arr:
            heapq.heappop(plus_arr)

while minus_arr:
    result += heapq.heappop(minus_arr)
    for _ in range(M - 1):
        if minus_arr:
            heapq.heappop(minus_arr)

print(-result * 2 - largest)