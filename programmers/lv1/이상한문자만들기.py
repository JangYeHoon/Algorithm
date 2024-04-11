def solution(s):
    answer = ''
    idx = 0
    for c in s:
        if c != ' ':
            if idx % 2 == 0:
                answer += c.upper()
            else:
                answer += c.lower()
            idx += 1
        else:
            answer += c
            idx = 0
    return answer

print(solution("try hello world"))