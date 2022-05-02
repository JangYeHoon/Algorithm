# fsat campus 강의
# https://www.acmicpc.net/problem/2110
# 1

n, c = map(int, input().split(' '))
array = []
for _ in range(n):
    array.append(int(input()))
array = sorted(array)

start = 0
end = array[-1]
while(start <= end):
    mid = (start + end) // 2
    pre_idx = 0
    count = 1
    for i in range(1, len(array)):
        if array[i] - array[pre_idx] >= mid:
            pre_idx = i
            count += 1
            
    if count >= c:
        start = mid + 1
    else:
        end = mid - 1
print(end)