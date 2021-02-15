N, K = map(int, input().split(' '))

n_list = list(map(int, input().split(' ')))

n_list = sorted(n_list)

print(n_list[K - 1])