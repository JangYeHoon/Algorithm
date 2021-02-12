N = int(input())

n_list = []
while N > 0:
    n_list.append(N % 10)
    N = int(N / 10)

n_list.sort(reverse=True)

for i in range(len(n_list)):
    print(n_list[i], end="")