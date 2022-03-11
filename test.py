# 연산자끼워넣기, 뒤집기, 등수매기기, 배

N = int(input())
crane = list(map(int, input().split()))
M = int(input())
box = list(map(int, input().split()))

crane.sort(reverse=True)
box.sort(reverse=True)

result = 0
if crane[0] < box[0]:
    print(-1)
else:
    while True:
        if len(box) == 0:
            break
        for c in crane:
            for i in range(len(box)):
                if c >= box[i]:
                    box.pop(i)
                    break
        result += 1
    print(result)