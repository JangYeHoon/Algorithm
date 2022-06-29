# fast campus 강의
# https://www.acmicpc.net/problem/2655
# 1

n = int(input())
array = []
array.append((0, 0, 0, 0))

for index in range(1, n + 1):
    area, height, weight = map(int, input().split())
    array.append((index, area, height, weight))

array.sort(key=lambda data:data[3])
dp = [0] * (n + 1)

for i in range(1, n + 1):
    for j in range(0, i):
        if array[i][1] > array[j][1]:
            dp[i] = max(dp[i], dp[j] + array[i][2])

result = []
max_value = max(dp)
index = n

while index != 0:
    if max_value == dp[index]:
        result.append(array[index][0])
        max_value -= array[index][2]
    index -= 1

result.reverse()
print(len(result))
[print(index) for index in result]