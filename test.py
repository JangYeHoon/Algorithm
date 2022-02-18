# 문자열재정렬, 문자열압축

N = list(map(int, input()))
idx = int(len(N) / 2)

if (sum(N[:idx]) == sum(N[idx:])):
    print("LUCKY")
else:
    print("READY")