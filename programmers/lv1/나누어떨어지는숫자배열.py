def solution(arr, divisor):
    answer = []
    for a in arr:
        if a % divisor == 0:
            answer.append(a)
    if len(answer) == 0:
        return [-1]
    else:
        return answer.sort()

print(solution([2, 36, 1, 3], 1))