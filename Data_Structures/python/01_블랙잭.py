n, m = map(int, input().split(' '))
num_list = list(map(int, input().split(' ')))

result = 0
for i in range(0, n):
    for j in range(0, n):
        for k in range(0, n):
            if i != j and i != k and j != k:
                temp = num_list[i] + num_list[j] + num_list[k]
                if m - result > m - temp:
                    if temp <= m:
                        result = temp

print(result)