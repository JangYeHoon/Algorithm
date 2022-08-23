# 이것이 취업을 위한 코딩테스트다
# 0

def count_by_value(array, x):
    n = len(array)

    a = first(array, x, 0, n - 1)

    if a == Nopne:
        return 0

    b = last(array, x, 0, n - 1)

    return b - a + 1


def first(array, target, start, end):
    if start > end:
        return None

    mid = (start + end) // 2
    if (mid == 0 or target > array[mid - 1]) and target == array[mid]:
        return mid
    elif array[mid] > target:
        first(array, target, start, mid - 1)
    else:
        first(array, target, mid + 1, end)


def last(array, target, start, end):
    if start > end:
        return None

    mid = (start + end) // 2
    if (mid == n - 1 or target < array[mid + 1]) and target == array[mid]:
        return mid
    elif array[mid] > target:
        last(array, target, start, mid - 1)
    else:
        last(array, target, mid + 1, end)


N, X = map(int, input().split())
array = list(map(int, input().split()))

count = count_by_value(array, X)

if count == 0:
    print(-1)
else:
    print(count)
