# fast campus 강의
# https://www.acmicpc.net/problem/2750
# 1

N = int(input())
sort_list = []
for _ in range(N):
    temp = int(input())
    sort_list.append(temp)

sort_list.sort()

for i in range(N):
    print(sort_list[i])