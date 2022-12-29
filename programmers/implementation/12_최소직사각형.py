# https://school.programmers.co.kr/learn/courses/30/lessons/86491

def solution(sizes):
    answer = [0, 0]
    for size in sizes:
        answer[0] = max(answer[0], max(size[0], size[1]))
        answer[1] = max(answer[1], min(size[0], size[1]))
    return answer[0] * answer[1]