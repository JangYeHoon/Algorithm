# 나이순정렬

N = input()
for i in range(9, -1, -1):
    for c in N:
        if int(c) == i:
            print(i, end='')