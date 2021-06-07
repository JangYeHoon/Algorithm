n = int(input())
arr = []

for _ in range(n):
    x = int(input())
    arr.append(x)

arr.sort()

result = 0
for i in range(0, n):
    result += abs((i + 1) - arr[i])

print(result)