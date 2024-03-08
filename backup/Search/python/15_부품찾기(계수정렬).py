# 이것이 취업을 위한 코딩테스트다 197p
# 1

N = int(input())
arr = [0] * 1000001
tmp_list = list(map(int, input().split()))
for i in tmp_list:
    arr[i] += 1

M = int(input())
tmp_list = list(map(int, input().split()))
for i in tmp_list:
    if arr[i] != 0:
        print("yes", end=' ')
    else:
        print("no", end=' ')