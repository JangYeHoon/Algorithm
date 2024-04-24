def solution(answers):
    score = [0, 0, 0]
    one = [1, 2, 3, 4, 5] * (len(answers)//2)
    two = [2, 1, 2, 3, 2, 4, 2, 5] * (len(answers)//2)
    three = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5] * (len(answers)//2)
    answer = []
    for i in range(len(answers)):
        if one[i] == answers[i]:
            score[0] += 1
        if two[i] == answers[i]:
            score[1] += 1
        if three[i] == answers[i]:
            score[2] += 1
    for i in range(1, 4):
        if max(score) == score[i-1]:
            answer.append(i)
    return answer