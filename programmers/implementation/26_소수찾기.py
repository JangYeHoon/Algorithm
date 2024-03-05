def solution(n):
    answer = 2 if n >= 3 else 1
    for i in range(2, n + 1):
        if i % 2 != 0 and i % 3 != 0:
            answer += 1
            print(i)
    return answer

print(solution(2))