# fast campus 강의
# https://www.acmicpc.net/problem/10989
# 1

import sys

N = int(sys.stdin.readline())

array = [0] * 10001

for _ in range(N):
    temp = int(sys.stdin.readline())
    array[temp] += 1

for i in range(10001):
    j = array[i]
    for _ in range(j):
        print(i)