def solution(n):
    answer = []
    while n:
        a = n % 3
        if a == 0:
            a = 4
            n -= 1
        answer.append(str(a))
        n //= 3
    return ''.join(answer[::-1])