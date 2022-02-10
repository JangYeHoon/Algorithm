# https://www.acmicpc.net/problem/9093
# 1

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