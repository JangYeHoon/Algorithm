# https://school.programmers.co.kr/learn/courses/30/lessons/86051

def solution(numbers):
    answer = 0
    for number in range(0, 10):
        if number not in numbers:
            answer += number
    # return 45 - sum(numbers)
    return answer