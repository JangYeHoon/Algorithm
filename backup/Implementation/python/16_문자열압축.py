# 이것이 취업을 위한 코딩테스트다 325p
# https://programmers.co.kr/learn/courses/30/lessons/60057
# 2

def solution(s):
    answer = 1e9
    if len(s) == 1:
        return 1
    for cnt in range(1, int(len(s) / 2 + 1)):
        result = ""
        str_cnt = 1
        tmp = s[0 : 0 + cnt]
        for i in range(cnt, len(s), cnt):
            if tmp == s[i : i + cnt]:
                str_cnt += 1
            else:
                if str_cnt == 1:
                    result += tmp
                else:
                    result += str(str_cnt) + tmp
                tmp = s[i : i + cnt]
                str_cnt = 1
        if str_cnt == 1:
            result += tmp
        else:
            result += str(str_cnt) + tmp
        answer = min(answer, len(result))
    return answer

print(solution(input()))