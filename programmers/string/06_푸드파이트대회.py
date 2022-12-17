# https://school.programmers.co.kr/learn/courses/30/lessons/134240

def solution(food):
    answer = ''
    for i in range(1, len(food)):
        answer += str(i) * (food[i] // 2)
    return answer + '0' + "".join(reversed(answer))