list_temp = list(map(int, input().split()))

result = False

for i in range(0, 8):
    if list_temp[i] != i + 1:
        result = True
        break
    elif i+1 == 8:
        print("ascending")

if result == True:
    for i in range(0, 8):
        if list_temp[i] != 8-i:
            result = True
            break
        elif i+1 == 8:
            print("descending")
            result = False

if result == True:
    print("mixed")