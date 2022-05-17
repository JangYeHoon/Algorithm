# 이것이 취업을 위한 코딩테스트다 197p
# 1

def binary_search(arr, target, start, end):
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
    return None

N = int(input())
arr = list(map(int, input().split()))
arr.sort()
M = int(input())
tmp_list = list(map(int, input().split()))

for i in tmp_list:
    result = binary_search(arr, i, 0, N - 1)
    if result != None:
        print("yes", end=" ")
    else:
        print("no", end=" ")