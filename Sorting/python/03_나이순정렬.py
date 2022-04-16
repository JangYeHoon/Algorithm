# fast campus 강의
# https://www.acmicpc.net/problem/10814
# 2

N = int(input())

person = []
for _ in range(N):
    age, name = input().split(' ')
    person.append([int(age), name])

result = sorted(person, key=lambda x:x[0])

for i in range(len(result)):
    print("{} {}".format(result[i][0], result[i][1]))