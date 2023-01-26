# https://school.programmers.co.kr/learn/courses/30/lessons/68935

def solution(n):
    answer = ''
    while n > 0:
        n, mod = divmod(n, 3)
        answer += str(mod)
    answer = int(answer, 3)
    return answer