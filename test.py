# 0만들기

result = 0
N, r, c = map(int, input().split())


def recursive(x, y, n):
    global result
    if x == r and y == c:
        print(result)
        exit(0)
    elif n == 1:
        result += 1
        return
    if not (x <= r < x + n) and not (y <= c < y + n):
        result += n ** 2
        return
    recursive(x, y, n // 2)
    recursive(x, y + n // 2, n // 2)
    recursive(x + n // 2, y, n // 2)
    recursive(x + n // 2, y + n // 2, n // 2)


recursive(0, 0, 2 ** N)
