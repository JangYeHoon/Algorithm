# fast campus 강의
# https://www.acmicpc.net/problem/2014
# 1

import heapq
import copy

K, N = map(int, input().split())
p_list = list(map(int, input().split()))

lst = copy.deepcopy(p_list)

heapq.heapify(lst)
index = 0
while index < N:
    mn = heapq.heappop(lst)
    index += 1
    for i in p_list:
        if mn * i < 2 ** 32:
            heapq.heappush(lst, mn * i)
            if mn % i == 0:
                break

print(mn)