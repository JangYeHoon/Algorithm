# 이것이 취업을 위한 코딩테스트다 321p
# https://www.acmicpc.net/problem/18406
# 2

N = list(map(int, input()))
idx = int(len(N)/2)
if sum(N[:idx]) == sum(N[idx:]):
    print("LUCKY")
else:
    print("READY")