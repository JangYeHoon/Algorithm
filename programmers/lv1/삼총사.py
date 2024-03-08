# https://school.programmers.co.kr/learn/courses/30/lessons/131705?language=python3

from itertools import combinations

def solution(number):
    answer = 0
    
    for three in combinations(number, 3):
        cnt = 0;
        for i in three:
            cnt += i
        if cnt == 0:
            answer += 1

    return answer