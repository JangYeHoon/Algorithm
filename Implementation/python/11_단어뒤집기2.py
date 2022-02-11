# fast campus 강의
# https://www.acmicpc.net/problem/17413
# 1

S = input()
temp, result, ck = "", "", False

for s in S:
    if s == ' ':
        if not ck:
            result += temp[::-1] + ' '
            temp = ""
        else: result += ' '
    elif s == '<':
        ck = True
        result += temp[::-1] + '<'
        temp = ""
    elif s == '>':
        ck = False
        result += '>'
    else:
        if ck: result += s
        else: temp += s

result += temp[::-1]
print(result)