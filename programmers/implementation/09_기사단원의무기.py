# https://school.programmers.co.kr/learn/courses/30/lessons/136798

def divisor_count(n):
    ret = 0
    for i in range(1, int(n ** (1/2)) + 1):
        if n % i == 0:
            ret += 1
            if i ** 2 != n:
                ret += 1
    return ret

def solution(number, limit, power):
    answer = 0
    for i in range(1, number + 1):
        cnt = divisor_count(i)
        if cnt <= limit:
            answer += cnt
        else:
            answer += power
    return answer