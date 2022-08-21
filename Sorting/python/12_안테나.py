# 이것이 취업을 위한 코딩테스트다
# https://www.acmicpc.net/problem/18310
# 2

N = int(input())
arr = sorted(list(map(int, input().split())))
print(arr[(N - 1) // 2])
