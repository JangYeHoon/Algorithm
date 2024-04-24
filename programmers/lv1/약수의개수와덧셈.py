def divisor_count(n):
    ret = 0
    for i in range(1, int(n ** (1/2)) + 1):
        if n % i == 0:
            ret += 1
            if i ** 2 != n:
                ret += 1
    return ret

def solution(left, right):
    answer = 0
    for i in range(left, right+1):
        if divisor_count(i) % 2 == 0:
            answer += i
        else:
            answer -= i
    return answer