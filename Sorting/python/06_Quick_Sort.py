def qsort(data):
    if len(data) <= 1:
        return data

    left, right = list(), list()
    pivot = data[0]

    for index in range(1, len(data)):
        if pivot > data[index]:
            left.append(data[index])
        else:
            right.append(data[index])
    
    return qsort(left) + [pivot] + qsort(right)

N = int(input())

n_list = []
for _ in range(N):
    n_list.append(int(input()))

result = qsort(n_list)

for i in range(N):
    print(result[i])