import heapq

n = int(input())

arr = []
for _ in range(n):
    dead, cup = map(int, input().split(' '))
    arr.append((dead, cup))

arr.sort()

result = []
for deadline, cup in arr:
    heapq.heappush(result, cup)
    if len(result) > deadline:
        heapq.heappop(result)

print(sum(result))