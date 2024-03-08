# 이것이 취업을 위한 코딩테스트다 197p
# 2

N = int(input())
arr = sorted(list(map(int, input().split())))
M = int(input())
chk = list(map(int, input().split()))

def binary_search(target, start, end):
    if start > end:
        return -1
    mid = (start + end) // 2
    if arr[mid] == target:
        return mid
    elif arr[mid] < target:
        return binary_search(target, mid + 1, end)
    else:
        return binary_search(target, start, mid - 1)

for i in chk:
    if binary_search(i, 0, N - 1) != -1:
        print("yes", end=" ")
    else:
        print("no", end=" ")