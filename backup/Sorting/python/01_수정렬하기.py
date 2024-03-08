# fast campus 강의
# https://www.acmicpc.net/problem/2750
# 2

N = int(input())
arr = []
for _ in range(N):
    arr.append(int(input()))
arr.sort()

for i in arr:
    print(i)