N = int(input())

array = []
left_result = 0
max_length = 0
for _ in range(N):
    array.append(int(input()))
    if array[-1] > max_length:
        left_result += 1
        max_length = array[-1]

max_length = 0
right_result = 0
array.reverse()
for i in range(N):
    if array[i] > max_length:
        right_result += 1
        max_length = array[i]

print(left_result)
print(right_result)