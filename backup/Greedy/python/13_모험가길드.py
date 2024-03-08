# 이것이 취업을 위한 코딩테스트다 311p
# 2

N = int(input())
lst = sorted(list(map(int, input().split())))

result = 0
count = 0
for i in lst:
    count += 1
    if count >= i:
        result += 1
        count = 0
print(result)