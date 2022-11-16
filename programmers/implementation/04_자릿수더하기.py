# https://school.programmers.co.kr/learn/courses/30/lessons/12931?language=python3

def solution(n):
    answer = 0
    
    s = str(n)
    for i in s:
        answer += int(i)

    return answer