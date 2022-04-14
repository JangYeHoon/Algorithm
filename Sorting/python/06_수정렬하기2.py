# fast campus 강의
# https://www.acmicpc.net/problem/2751
# 1

n = int(input())
array = []

for _ in range(n):
    array.append(int(input()))

array = sorted(array)

for data in array:
    print(data)