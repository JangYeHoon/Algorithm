def solution(num):
    answer = 0
    while (answer <= 500):
        if num == 1:
            break
        answer += 1
        if num % 2 == 0:
            num //= 2
        else:
            num = num * 3 + 1
    return answer if answer <= 500 else -1