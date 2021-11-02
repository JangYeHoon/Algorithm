# fast campus 강의
# https://www.acmicpc.net/problem/16676
# 1

# 한자리 수에서는 1장만 필요
# 두자리 수에서는 11에서 2장 필요
# 11보다 작으면 1장
# 111보다 작으면 2장
# 1111보다 작으면 3장

N = input()
S = '1' * len(N)

if len(N) == 1:
    print(1)
elif int(N) >= int(S):
    print(len(N))
else:
    print(len(N) - 1)