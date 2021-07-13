N, M = map(int, input().split())
group_dict = {}

for i in range(N):
    group_name, member_num = input(), int(input())
    members = []
    for j in range(member_num):
        members.append(input())
    members.sort()
    group_dict[group_name] = members

for i in range(M):
    exam_name, exam_num = input(), int(input())
    if exam_num == 0:
        members = group_dict.get(exam_name)
        for member in members:
            print(member)
    else:
        for group_name, members in group_dict.items():
            if exam_name in members:
                print(group_name)