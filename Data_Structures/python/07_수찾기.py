N = int(input())
key = list(map(int, input().split(' ')))
key_dict = {}
for i in range(0, N):
    key_dict[key[i]] = 1

M = int(input())
value = list(map(int, input().split(' ')))
for i in range(0, M):
    if key_dict.get(value[i]):
        print(1)
    else:
        print(0)