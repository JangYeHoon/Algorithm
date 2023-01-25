# https://school.programmers.co.kr/learn/courses/30/lessons/77484#fn1

from collections import Counter

def solution(lottos, win_nums):
    ranking = [6, 6, 5, 4, 3, 2, 1]
    match_cnt = 0
    zero_cnt = 0
    lottos_counter = Counter(win_nums)
    for i in range(6):
        if lottos[i] == 0:
            zero_cnt += 1
            continue
        if lottos_counter.get(lottos[i]) != None:
            match_cnt += 1
    return [ranking[match_cnt + zero_cnt], ranking[match_cnt]]