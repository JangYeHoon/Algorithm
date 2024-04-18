def solution(x, n):
    lst = list(x for i in range(n))
    return list(lst[i-1] * i for i in range(1, n + 1))