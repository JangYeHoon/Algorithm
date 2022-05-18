# 이것이 취업을 위한 코딩테스트다
# 1

def binary_search(start, end):
    if start > end:
        return -1
    mid = (start + end) // 2
    result = 0
    for i in arr:
        if i > mid:
            result += i - mid
    if result == M:
        return mid
    elif result > M:
        return binary_search(mid + 1, end)
    else:
        return binary_search(start, mid - 1)

N, M = map(int, input().split())
arr = list(map(int, input().split()))

print(binary_search(0, max(arr)))