# 이것이 취업을 위한 코딩테스트다 346p
# https://programmers.co.kr/learn/courses/30/lessons/60058
# 2

def balance(p):
    cnt = 0
    for i in range(len(p)):
        if p[i] == '(':
            cnt += 1
        else:
            cnt -= 1
        if cnt == 0:
            return i

def check(p):
    cnt = 0
    for i in p:
        if i == '(':
            cnt += 1
        else:
            if cnt == 0:
                return False
            cnt -= 1
    return True

def solution(p):
    answer = ''
    if p == '':
        return answer
    idx = balance(p)

    u = p[:idx + 1]
    v = p[idx + 1:]

    if check(u):
        answer = u + solution(v)
    else:
        answer = '('
        answer += solution(v)
        answer += ')'
        u = list(u[1:-1])
        for i in range(len(u)):
            if u[i] == '(':
                u[i] = ')'
            else:
                u[i] = '('
        answer += "".join(u)
    return answer

print(solution(input()))