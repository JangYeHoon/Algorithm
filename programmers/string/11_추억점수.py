# https://school.programmers.co.kr/learn/courses/30/lessons/176963

def solution(name, yearning, photo):
    answer = []
    score = dict(zip(name, yearning))
    
    for i in range(len(photo)):
        cnt = 0
        for photo_name in photo[i]:
            if photo_name in score:
                cnt += score[photo_name]
        answer.append(cnt)
    return answer