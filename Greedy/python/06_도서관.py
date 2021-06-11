n, m = map(int, input().split())

def calc_distance(array, end_check):
    step = 0
    if len(array) % m != 0:
        step = len(array) % m
    else:
        step = m

    cnt = 0
    for i in range(step - 1, len(array), m):
        if i == len(array) - 1 and end_check == True:
            cnt += abs(array[i])
        else:
            cnt += abs(array[i]) * 2
    return cnt

arr = list(map(int, input().split()))

arr_minus = []
arr_plus = []
for i in range(n):
    if arr[i] < 0:
        arr_minus.append(arr[i])
    else:
        arr_plus.append(arr[i])

arr_minus.sort(reverse=True)
arr_plus.sort()

end_check = 1
if arr_minus and arr_plus:
    if abs(arr_minus[-1]) > max(arr_plus):
        end_check = -1
else:
    if not arr_minus:
        end_check = 1
    elif not arr_plus:
        end_check = -1

result = 0
if end_check == -1:
    result += calc_distance(arr_minus, True)
    result += calc_distance(arr_plus, False)
else:
    result += calc_distance(arr_minus, False)
    result += calc_distance(arr_plus, True)

print(result)