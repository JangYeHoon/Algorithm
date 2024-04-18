import itertools

def isPrime(n):
    for i in range(2, n):
        if n % i == 0: return False
        if i * i > n: break
    return True

def solution(nums):
    answer = 0

    for i in itertools.combinations(nums, 3):
        if isPrime(sum(i)):
            answer += 1

    return answer