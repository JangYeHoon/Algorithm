n = int(input())
array = [] * n

for i in range(n):
    tempArray = list(map(int, input().split()))
    array.append(tempArray)

resultArray = [[0] * (n + 1) for _ in range(n + 1)]
for i in range(1, n + 1):
    resultArray[0][i] = array[i - 1][1]
for i in range(1, n + 1):
    resultArray[i][0] = array[i - 1][1]

tempArray = []
result = []
maxHeight = -1
for i in range(1, n + 1):
    tempArray.append(i)
    for j in range(1, n + 1):
        if i == j:
            resultArray[i][j] = resultArray[i][j - 1]
            continue
        if array[tempArray[-1] - 1][0] > array[j - 1][0] and array[tempArray[-1] - 1][2] > array[j - 1][2]:
            tempArray.append(j)
            resultArray[i][j] = resultArray[i][j - 1] + resultArray[0][j]
        else:
            resultArray[i][j] = resultArray[i][j - 1]
    if resultArray[i][n] > maxHeight:
        result = tempArray
        maxHeight = resultArray[i][n]
    tempArray = []
    
num = len(result)
print(num)
for i in range(num - 1, -1, -1):
    print(result[i])