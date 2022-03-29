# 이것이 취업을 위한 코딩테스트다 312p
# 1

S = input()
result = int(S[0])
for i in range(1, len(S)):
    if int(S[i]) <= 1 or result <= 1:
        result += int(S[i])
    else:
        result *= int(S[i])
print(result)