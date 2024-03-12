def solution(n):
    ret = [n]
    for i in range(1, n//2 + 1):
        if n % i == 0:
            ret.append(i)
    return sum(set(ret)) if n > 0 else 0