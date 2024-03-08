# 이것이 취업을 위한 코딩테스트다 349p
# https://www.acmicpc.net/problem/14888
# 2

def dfs(idx, num):
    global max_value, min_value, add, sub, mul, div
    if idx == N:
        max_value = max(max_value, num)
        min_value = min(min_value, num)
    else:
        if add > 0:
            add -= 1
            dfs(idx + 1, num + A[idx])
            add += 1
        if sub > 0:
            sub -= 1
            dfs (idx + 1, num - A[idx])
            sub += 1
        if mul > 0:
            mul -= 1
            dfs(idx + 1, num * A[idx])
            mul += 1
        if div > 0:
            div -= 1
            dfs(idx + 1, int(num / A[idx]))
            div += 1

N, A = int(input()), list(map(int, input().split()))
add, sub, mul, div = map(int, input().split())
max_value, min_value = -1e9, 1e9

dfs(1, A[0])

print(max_value)
print(min_value)