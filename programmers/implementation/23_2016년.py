# https://school.programmers.co.kr/learn/courses/30/lessons/12901#

def solution(a, b):
    month = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    week = ['THU', 'FRI', 'SAT', 'SUN', 'MON', 'TUE', 'WED']
    day = b
    
    for i in range(a - 1):
        day += month[i]
    return week[day % 7]