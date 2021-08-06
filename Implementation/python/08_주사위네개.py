n, dice = int(input()), []
result = 0

for i in range(n):
    dice.append(list(map(int, input().split())))
    cnt = len(set(dice[i]))
    dice[i].sort()

    if cnt == 1:
        result = max(result, 50000 + dice[i][0] * 5000)
    elif cnt == 2:
        if dice[i][0] == dice[i][1] and dice[i][2] == dice[i][3]:
            result = max(result, 2000 + dice[i][0] * 500 + dice[i][2] * 500)
        else:
            result = max(result, 10000 + dice[i][1] * 1000)
    elif cnt == 3:
        if dice[i][1] == dice[i][2]:
            result = max(result, 1000 + dice[i][1] * 100)
        elif dice[i][0] == dice[i][1]:
             result = max(result, 1000 + dice[i][1] * 100)
        else:
            result = max(result, 1000 + dice[i][2] * 100)
    else:
        result = max(result, max(dice[i]) * 100)

print(result)