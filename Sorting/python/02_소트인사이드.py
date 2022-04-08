# fast campus 강의
# https://www.acmicpc.net/problem/1427
# 1

array = input()

for i in range(9, -1, -1):
    for j in array:
        if int(j) == i:
            print(i, end='')