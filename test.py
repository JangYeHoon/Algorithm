# 주사위세개, 주사위네개

N = int(input())

result = 0
for i in range(N):
    dice = sorted(list(map(int, input().split())))
    
    cnt = len(set(dice))
    if cnt == 1:
        result = max(result, 50000 + dice[0] * 5000)
    elif cnt == 2:
        if dice[1] == dice[2]:
            result = max(result, 10000 + dice[1] * 1000)
        else:
            result = max(result, 2000 + dice[1] * 500 + dice[2] * 500)
    elif cnt == 3:
        for i in range(3):
            if dice[i] == dice[i + 1]:
                result = max(result, 1000 + dice[i] * 100)
                break
    else:
        result = max(result, dice[3] * 100)
print(result)