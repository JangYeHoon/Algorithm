# 주사위세개, 주사위네개, 두개의손, 단어뒤집기, 단어뒤집기2

S = input()
tmp, result = "", ""
tag_chk = False

for s in S:
    if s == ' ':
        if tag_chk:
            result += s
        else:
            result += tmp[::-1] + ' '
            tmp = ""
    elif s == '<':
        tag_chk = True
        result += tmp[::-1] + '<'
        tmp = ""
    elif s == '>':
        tag_chk = False
        result += '>'
    else:
        if tag_chk:
            result += s
        else:
            tmp += s
result += tmp[::-1]
print(result)