# 이것이 취업을 위한 코딩테스트다
# 1

def array_by_count(arr, x):
    a = left_count(arr, x, 0, N - 1)

    if a == None:
        return -1

    b = right_count(arr, x, 0, N - 1)
    return b - a + 1


def left_count(arr, target, start, end):
    if start > end:
        return None

    mid = (start + end) // 2
    if (mid == 0 or target > arr[mid - 1]) and target == arr[mid]:
        return mid
    elif arr[mid] >= target:
        return left_count(arr, target, start, mid - 1)
    else:
        return left_count(arr, target, mid + 1, end)


def right_count(arr, target, start, end):
    if start > end:
        return None

    mid = (start + end) // 2
    if (mid == N - 1 or target < arr[mid + 1]) and target == arr[mid]:
        return mid
    elif arr[mid] > target:
        return right_count(arr, target, start, mid - 1)
    else:
        return right_count(arr, target, mid + 1, end)


N, X = map(int, input().split())
arr = list(map(int, input().split()))

count = array_by_count(arr, X)

print(count)
