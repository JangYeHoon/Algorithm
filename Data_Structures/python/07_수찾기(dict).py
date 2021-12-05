# fast campus 강의
# https://www.acmicpc.net/problem/1920
# 2

N = int(input())
A = {i : 1 for i in list(map(int, input().split()))}
M = int(input())

for i in list(map(int, input().split())):
    print(A.get(i, 0))