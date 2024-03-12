def solution(s, n):
    answer = ''
    for c in s:
        if c == ' ':
            answer += c
        else:
            tmp = ord(c)
            for _ in range(n):
                tmp += 1
                if tmp == 123 or tmp == 91:
                    if 'a' <= c <= 'z':
                        tmp = 97
                    else:
                        tmp = 65
            answer += chr(tmp)
    return answer