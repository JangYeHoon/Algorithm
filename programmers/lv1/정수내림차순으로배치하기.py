def solution(n):
    lst = sorted(list(str(n)), reverse=True)
    answer = 0
    for i in lst:
        answer += int(i)
        answer *= 10
    return answer/10