# fast campus 강의
# https://www.acmicpc.net/problem/11004
# 1

N, K = map(int, input().split(' '))

n_list = list(map(int, input().split(' ')))

n_list = sorted(n_list)

print(n_list[K - 1])