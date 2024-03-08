# fast campus 강의
# https://www.acmicpc.net/problem/1092
# 2

import sys

n = int(input())
cranes = list(map(int, input().split()))

m = int(input())
boxes = list(map(int, input().split()))

if max(cranes) < max(boxes):
    print(-1)
    sys.exit()

cranes.sort(reverse=True)
boxes.sort(reverse=True)

position = [0] * n
checked = [False] * m

result = 0
count = 0
while True:
    if count == len(boxes):
        break
    for i in range(n):
        while position[i] < len(boxes):
            if not checked[position[i]] and cranes[i] >= boxes[position[i]]:
                checked[position[i]] = True
                position[i] += 1
                count += 1
                break
            position[i] += 1
    result += 1

print(result)

# N = int(input())
# crane = list(map(int, input().split()))
# M = int(input())
# box = list(map(int, input().split()))

# crane.sort(reverse=True)
# box.sort(reverse=True)

# result = 0
# if crane[0] < box[0]:
#     print(-1)
# else:
#     while True:
#         if len(box) == 0:
#             break
#         for c in crane:
#             for i in range(len(box)):
#                 if c >= box[i]:
#                     box.pop(i)
#                     break
#         result += 1
#     print(result)