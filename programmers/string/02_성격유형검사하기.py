# https://school.programmers.co.kr/learn/courses/30/lessons/118666?language=python3

def solution(survey, choices):
    answer = ''
    category = ['R', 'T', 'C', 'F', 'J', 'M', 'A', 'N']
    personality = {}
    for i in range(len(category)):
        personality[category[i]] = 0
    
    for i in range(len(survey)):
        if choices[i] == 4:
            continue
        elif choices[i] < 4:
            personality[survey[i][0]] += 4 - choices[i]
        else:
            personality[survey[i][1]] += choices[i] - 4
    
    for i in range(0, len(category), 2):
        if personality[category[i]] >= personality[category[i + 1]]:
            answer += category[i]
        else:
            answer += category[i + 1]
    return answer