# fast campus 강의
# https://www.acmicpc.net/source/35583700
# 1

n, m = map(int, input().split(' '))
data = list(map(int, input().split(' ')))

result = 0
length = len(data)

count = 0
for i in range(0, length):
    for j in range(i + 1, length):
        for k in range(j + 1, length):
            sum_value = data[i] + data[j] + data[k]
            if sum_value <= m:
                result = max(result, sum_value)

print(result)