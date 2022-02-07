# fast campus 강의
# https://www.acmicpc.net/problem/2480
# 1

arr = list(map(int, input().split()))

n = len(set(arr))

if n == 1:
    print(10000 + arr[0] * 1000)
elif n == 2:
    arr.sort()
    print(1000 + arr[1] * 100)
else:
    print(max(arr) * 100)