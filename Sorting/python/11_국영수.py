# 이것이 취업을 위한 코딩테스트다
# https://www.acmicpc.net/problem/10825
# 2

N = int(input())

students = []
for _ in range(N):
    students.append(input().split())

students.sort(key=lambda x: (-int(x[1]), int(x[2]), -int(x[3]), x[0]))

for student in students:
    print(student[0])
