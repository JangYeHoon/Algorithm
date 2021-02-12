N = int(input())

num_list = []

for _ in range(N):
    n1, n2 = input().split(' ')
    num_list.append((int(n1), int(n2)))

num_list = sorted(num_list, key=lambda x:(x[0], x[1]))

for key in num_list:
    print("{} {}".format(key[0], key[1]))