def solution(dartResult):
    answer = []
    bonus = ['S', 'D', 'T']
    idx = 0
    while idx < len(dartResult):
        if '0' <= dartResult[idx] <= '9':
            if dartResult[idx] == '1' and dartResult[idx+1] == '0':
                answer.append(int(dartResult[idx]+dartResult[idx+1]))
                idx += 2
            else:
                answer.append(int(dartResult[idx]))
                idx += 1
        if dartResult[idx] in bonus:
            if dartResult[idx] == 'D':
                answer[-1] = answer[-1] ** 2
            elif dartResult[idx] == 'T':
                answer[-1] = answer[-1] ** 3
            idx += 1
        if idx >= len(dartResult):
            break
        if dartResult[idx] == '*':
            answer[-1] *= 2
            if len(answer) > 1:
                answer[-2] *= 2
            idx += 1
        elif dartResult[idx] == '#':
            answer[-1] *= -1
            idx += 1
    return sum(answer)

print(solution("1D2S#10S"))