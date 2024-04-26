# def solution(n, m, section):
#     answer = 1
#     prev = section[0]
#     for sec in section:
#         if sec - prev >= m:
#             prev = sec
#             answer += 1

#     return answer

def solution(n, m, section):
    answer = 0
    full = [1] * (n + 1)
    for s in section:
        full[s] = 0
    for s in section:
        if full[s] == 0:
            answer += 1
            for i in range(m):
                if s+i > n:
                    break
                full[s+i] = 1
    return answer