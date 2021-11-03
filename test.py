# 뒤집기, 근우다이어리, 저울
N = input()
S = '1' * len(N)

if len(N) == 1:
    print(1)
elif int(N) >= int(S):
    print(len(N))
else:
    print(len(N) - 1)