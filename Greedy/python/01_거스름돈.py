# fast campus 강의
# https://www.acmicpc.net/problem/5585
# 1

changes = 1000 - int(input())
count = 0

for i in [500, 100, 50, 10, 5, 1]:
    count += changes // i
    changes %= i

print(count)