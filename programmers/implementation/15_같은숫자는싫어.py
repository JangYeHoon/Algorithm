# https://school.programmers.co.kr/learn/courses/30/lessons/12906?language=python3

def solution(arr):
    answer = [arr[0]]
    for i in range(1, len(arr)):
        if arr[i - 1] != arr[i]:
            answer.append(arr[i])
    return answer