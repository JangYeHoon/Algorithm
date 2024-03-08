def solution(n):
    answer = -1
    for i in range(int(n ** 1/2) + 2):
        if n == i**2:
            answer = (i + 1)**2
            break
    return answer