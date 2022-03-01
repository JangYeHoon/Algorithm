# 이것이 취업을 위한 코딩테스트다 332p
# https://www.acmicpc.net/problem/15686
# 1

import itertools

N, M = map(int, input().split())
chicken, house = [], []
for i in range(1, N + 1):
    tmp_list = list(map(int, input().split()))
    for j in range(1, N + 1):
        if tmp_list[j - 1] == 2:
            chicken.append((i, j))
        elif tmp_list[j - 1] == 1:
            house.append((i, j))

result = 1e9
for chiken_list in list(itertools.combinations(chicken, M)):
    sum_distance = 0
    for hx, hy in house:
        min_distance = 1e9
        for cx, cy in chiken_list:
            min_distance = min(min_distance, abs(hx - cx) + abs(hy - cy))
        sum_distance += min_distance
    result = min(result, sum_distance)
print(result)