# 연산자끼워넣기, 뒤집기, 등수매기기

N = int(input())
arr = []
for _ in range(N):
    arr.append(int(input()))

arr.sort()

result = 0
for i in range(N):
    result += abs((i + 1) - arr[i])
print(result)