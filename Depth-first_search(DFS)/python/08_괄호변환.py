# 
# https://programmers.co.kr/learn/courses/30/lessons/60058
# 0

# 균형잡힌 괄호 문자열의 인덱스 반환
def balance(p):
    cnt = 0 # 왼쪽 괄호의 개수
    for i in range(len(p)):
        if p[i] == '(':
            cnt += 1
        else:
            cnt -= 1
        if cnt == 0:
            return i

# 올바른 괄호 문자열인지 판단
def check(p):
    cnt = 0
    for i in range(len(p)):
        if p[i] == '(':
            cnt += 1
        else:
            if cnt == 0:
                return False
            cnt -= 1
    return True
    
def solution(p):
    answer = ''
    # 빈 문자열이면 바로 반환
    if p == '':
        return answer
    
    # 균형잡힌 괄호 문자열 u, v분리를 위한 더 이상 분리할 수 없는 수 확인
    cnt = balance(p)
    u = p[:cnt + 1]
    v = p[cnt + 1:]
    
    # 올바른 괄호 문자열이면, v에 대해 함수를 수행한 결과를 붙여 반환
    if check(u):
        answer = u + solution(v)
    # 올바른 괄호 문자열이 아니라면 아래의 과정을 수행
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