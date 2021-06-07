n = int(input())
crane = list(map(int, input().split()))

m = int(input())
box = list(map(int, input().split()))

box.sort(reverse=True)
crane.sort(reverse=True)

time = 0
while box:
    if box[0] > crane[0]:
        break
    for i in range(n):
        for j in box:
            if crane[i] > j:
                box.remove(j)
                break
    time += 1

if len(box):
    print(-1)
else:
    print(time)