S = input()

str_list = []
temp = ""
ck = False
for i in range(len(S)):
    if S[i] == '<':
        if i != 0 and temp != "":
            for s in temp.split(' '):
                str_list.append(s)
                str_list.append(' ')
            str_list.pop()
            temp = ""
        ck = True
        temp += S[i]
    elif ck == True:
        if S[i] == '>':
            ck = False
            temp += S[i]
            str_list.append(temp)
            temp = ""
        else:
            temp += S[i]
    else:
        if S[i] == ' ' or i == len(S) - 1:
            if i == len(S) - 1:
                temp += S[i]
            str_list.append(temp)
            str_list.append(' ')
            temp = ""
        else:
            temp += S[i]

result = ""
for s in str_list:
    if s[0] == '<':
        result += s
    else:
        if s == ' ':
            result += s
        else:
            result += s[::-1]

print(result)