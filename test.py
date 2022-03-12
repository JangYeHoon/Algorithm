# 

N = int(input())
crane = list(map(int, input().split()))
M = int(input())
box = list(map(int, input().split()))

crane.sort(reverse=True)
box.sort(reverse=True)

if crane[0] < box[0]:
    print(-1)
    exit()

position = [0] * N
check = [False] * M
result = 0
count = 0
while 1:
    if count == len(box):
        break
    for i in range(N):
        while position[i] < len(box):
            if not check[position[i]] and crane[i] >= box[position[i]]:
                check[position[i]] = True
                position[i] += 1
                count += 1
                break
            position[i] += 1
    result += 1
print(result)