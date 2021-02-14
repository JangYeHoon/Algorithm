result = 0
def Z(n, x, y):
    global result
    if n == 2:
        check = False
        if x == r and y == c:
            print(result)
            check = True
        result += 1
        if x == r and y + 1 == c:
            print(result)
            check = True
        result += 1
        if x + 1 == r and y == c:
            print(result)
            check = True
        result += 1
        if x + 1 == r and y + 1 == c:
            print(result)
            check = True
        result += 1
        return check
    if Z(n / 2, x, y): return True
    if Z(n / 2, x, y + n / 2): return True
    if Z(n / 2, x + n / 2, y): return True
    if Z(n / 2, x + n / 2, y + n / 2): return True
    return False

N, r, c = map(int, input().split(' '))
Z(2 ** N, 0, 0)