N = int(input())

index = 1
result = 0
while N > 0:
    result += 1
    if index > N:
        index = 1
    N -= index
    index += 1
print(result)