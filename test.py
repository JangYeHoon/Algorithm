# 치킨배달(c++), 외벽전검, 거스름돈

from itertools import combinations

N, M = map(int, input().split())
house_list = []
chiken_list = []
for i in range(N):
    temp = list(map(int, input().split()))
    for j in range(N):
        if temp[j] == 1:
            house_list.append((i, j))
        elif temp[j] == 2:
            chiken_list.append((i, j))

result = 1e9
for chikens in list(combinations(chiken_list, M)):
    dist = 0
    for hx, hy in house_list:
        house_dist = 1e9
        for cx, cy in chikens:
            house_dist = min(house_dist, abs(hx - cx) + abs(hy - cy))
        dist += house_dist
    result = min(result, dist)
print(result)