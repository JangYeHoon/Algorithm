# 수빈이와수열, 이름궁합테스트. TheCandyWar, 보너스점수, MixingMilk

N = int(input())
s = input()

bouns, result = 0, 0
for i in range(N):
    if s[i] == 'X':
        bouns = 0
    else:
        result += i + 1 + bouns
        bouns += 1
print(result)