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