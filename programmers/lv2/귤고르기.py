# https://school.programmers.co.kr/learn/courses/30/lessons/138476?language=python3

from collections import Counter


def solution(k, tangerine):
    answer = 0
    tangerine_set = Counter(tangerine)

    sorted_dict = sorted(tangerine_set.values(), reverse=True)
    for i in sorted_dict:
        answer += 1
        k -= i
        if k <= 0:
            break
    return answer
