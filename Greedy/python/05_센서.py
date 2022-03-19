# fast campus 강의
# https://www.acmicpc.net/problem/2212
# 2

import sys

n = int(input())
k = int(input())
if k >= n:
    print(0)
    sys.exit()

arr = list(map(int, input().split()))
arr.sort()

distance = [0] * (n - 1)
for i in range(n - 1):
    distance[i] = arr[i + 1] - arr[i]

for i in range(k - 1):
    distance.remove(max(distance))

print(sum(distance))