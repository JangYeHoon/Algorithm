# fast campus 강의
# https://www.acmicpc.net/problem/17269
# 1

N, M = map(int, input().split())
A, B = input().split()

alpabet = [3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1]

s = ""
tmp = min(N, M)
for i in range(tmp):
    s += A[i] + B[i]
s += A[tmp:] + B[tmp:]

result = [alpabet[ord(i) - ord('A')] for i in s]

for i in range(N + M - 2):
    for j in range(N + M - i - 1):
        result[j] = (result[j] + result[j + 1]) % 10

print("{}%".format(result[0] * 10 + result[1]))