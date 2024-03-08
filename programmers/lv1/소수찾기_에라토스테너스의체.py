def solution(n):
    primes = [True] * (n + 1)
    primes[0] = primes[1] = False

    for i in range(2, int(n ** 0.5) + 1):
        if primes[i]:
            for i in range(i*i, n + 1, i):
                primes[i] = False
    return primes.count(True)

print(solution(5))