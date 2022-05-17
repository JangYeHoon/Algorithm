# 이것이 취업을 위한 코딩테스트다 197p
# 1

N = int(input())
arr = set(map(int, input().split()))

M = int(input())
tmp_list = list(map(int, input().split()))

for i in tmp_list:
    if i in arr:
        print("yes", end=" ")
    else:
        print("no", end=" ")