# fast campus 강의
# https://www.acmicpc.net/problem/1302
# 1

N = int(input())

dic = {}
for _ in range(N):
    s = input()
    if s not in dic:
        dic[s] = 1
    else:
        dic[s] += 1

max_value = max(dic.values())
result = []

for key, value in dic.items():
    if value == max_value:
        result.append(key)

print(sorted(result)[0])