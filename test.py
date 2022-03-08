# 연산자끼워넣기, 뒤집기

N = 1000 - int(input())
result = 0
for c in [500, 100, 50, 10, 5, 1]:
    result += N // c
    N = N % c
print(result)