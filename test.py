# 자물쇠와열쇠, 뱀

def solution(s):
    answer = 1e9
    if len(s) == 1:
        return 1
    for cnt in range(1, int(len(s) / 2 + 1)):
        string_cnt = 1
        tmp = s[0 : 0 + cnt]
        result = ""
        for i in range(cnt, len(s), cnt):
            if tmp == s[i : i + cnt]:
                string_cnt += 1
            else:
                if string_cnt == 1:
                    result += tmp
                else:
                    result += str(string_cnt) + tmp
                tmp = s[i : i + cnt]
                string_cnt = 1
        if string_cnt == 1:
            result += tmp
        else:
            result += str(string_cnt) + tmp
        answer = min(answer, len(result))

    return answer

print(solution(input()))