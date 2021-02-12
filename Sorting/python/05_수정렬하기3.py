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