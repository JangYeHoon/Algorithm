# https://school.programmers.co.kr/learn/courses/30/lessons/138477

def solution(k, score):
    answer = []
    reward = []
    for i in score:
        reward.append(i)
        if len(reward) > k:
            reward.remove(min(reward))
        answer.append(min(reward))
    return answer