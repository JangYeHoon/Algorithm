# 주사위세개, 주사위네개, 두개의손, 단어뒤집기

for _ in range(int(input())):
    S = input()
    result, temp = "", ""

    for s in S:
        if s == ' ':
            result += temp[::-1] + ' '
            temp = ""
        else:
            temp += s
    print(result + temp[::-1])