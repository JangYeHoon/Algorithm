# fast campus 강의
# https://www.acmicpc.net/problem/15969
# 1

n, score_list = int(input()), list(map(int, input().split()))

print(max(score_list) - min(score_list))