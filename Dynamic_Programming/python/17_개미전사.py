# 이것이 취업을 위한 코딩테스트다 220p
# 2

N = int(input())
arr = list(map(int, input().split()))
d = [0] * (N + 1)

d[0] = arr[0]
d[1] = max(arr[0], arr[1])
for i in range(2, N):
    d[i] = max(d[i - 1], d[i - 2] + arr[i])

print(max(d))
