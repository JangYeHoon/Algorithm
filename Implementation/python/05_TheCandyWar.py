def check(N, candy_list):
    for i in range(N):
        if candy_list[i] % 2 == 1:
            candy_list[i] += 1
    return len(set(candy_list)) == 1

def teacher(N, candy_list):
    temp_list = [0 for i in range(N)]
    for i in range(N):
        if candy_list[i] % 2:
            candy_list[i] += 1
        candy_list[i] //= 2
        temp_list[(i + 1) % N] += candy_list[i]
    
    for i in range(N):
        candy_list[i] += temp_list[i]
    return candy_list

for i in range(int(input())):
    N, candy_list = int(input()), list(map(int, input().split()))
    result = 0
    while not check(N, candy_list):
        result += 1
        candy_list = teacher(N, candy_list)
    print(result)
