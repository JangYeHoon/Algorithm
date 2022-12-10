# https://school.programmers.co.kr/learn/courses/30/lessons/140108

def solution(s):
    answer = 0
    while len(s) > 0:
        x = s[0]
        same, different = 0, 0
        for i in range(0, len(s)):
            if x == s[i]:
                same += 1
            else:
                different += 1
            
            if same == different:
                s = s[i + 1:]
                answer += 1
                break
        if same != different:
            answer += 1
            break
    return answer