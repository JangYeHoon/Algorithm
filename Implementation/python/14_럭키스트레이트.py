# 이것이 취업을 위한 코딩테스트다. 
# https://www.acmicpc.net/problem/18406
# 1

N = list(map(int, input()))
idx = int(len(N)/2)
if sum(N[:idx]) == sum(N[idx:]):
    print("LUCKY")
else:
    print("READY")