N, r, c = map(int,input().split())
res = 0

def Z(x, y, N):
    global res
    if x == r and y == c:
        print(res)
        exit(0)
    elif N == 1:
        res += 1
        return
    if not (x <= r < x + N) and not (y <= c < y + N):
        res += N ** 2
        return
    Z(x, y, N // 2)
    Z(x, y + N // 2, N // 2)
    Z(x + N // 2, y, N // 2)
    Z(x + N // 2, y + N // 2, N // 2)
    
Z(0, 0, 2 ** N)