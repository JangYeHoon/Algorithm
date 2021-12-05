# fast campus 강의
# https://www.acmicpc.net/problem/1920
# 2

n = int(input())
array = set(map(int, input().split()))
m = int(input())
x = list(map(int, input().split()))

for i in x:
    if i not in array:
        print('0')
    else:
        print('1')