# 꽃길, 럭키스트레이트

S = input()
result, tmp = "", ""
tag_chk = False

for s in S:
    if s == ' ':
        if tag_chk:
            result += s
        else:
            result += tmp[::-1] + ' '
            tmp = ""
    elif s == '>':
        tag_chk = False
        result += '>'
    elif s == '<':
        tag_chk = True
        result += tmp[::-1] + '<'
        tmp = ""
    else:
        if tag_chk: result += s
        else: tmp += s
result += tmp[::-1]
print(result)