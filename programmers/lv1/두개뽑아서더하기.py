# https://school.programmers.co.kr/learn/courses/30/lessons/68644

from itertools import combinations

def solution(numbers):
    answer = []
    for i, j in combinations(numbers, 2):
        answer.append(i + j)
    return sorted(set(answer))