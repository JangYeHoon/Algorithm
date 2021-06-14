def is_available(row):
    for i in range(row):
        if queen[i] == queen[row] or abs(queen[row] - queen[i]) == row - i:
            return False
    return True

def dfs(row):
    global result
    if row == n:
        result += 1
    else:
        for i in range(n):
            queen[row] = i
            if is_available(row):
                dfs(row + 1)

n = int(input())
queen = [0] * n
result = 0
dfs(0)
print(result)