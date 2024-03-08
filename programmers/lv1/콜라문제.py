# https://school.programmers.co.kr/learn/courses/30/lessons/132267#

def solution(a, b, n):
    answer = 0
    while n >= a:
        quotient = n // a
        n = n - quotient * a + b * quotient
        answer += b * quotient
    return answer