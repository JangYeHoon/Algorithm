# fast campus 강의
# https://www.acmicpc.net/problem/16165
# 2

N, M = map(int, input().split())
team_mem, mem_team = {}, {}

for i in range(N):
    group_name, member_num = input(), int(input())
    team_mem[group_name] = []
    for j in range(member_num):
        member = input()
        team_mem[group_name].append(member)
        mem_team[member] = group_name

for i in range(M):
    exam_name, exam_num = input(), int(input())
    if exam_num:
        print(mem_team[exam_name])
    else:
        for member in sorted(team_mem[exam_name]):
            print(member)