import copy

result = []
string = []
visited = []

def combination(array, length, index):
    if len(string) == length:
        result.append(copy.deepcopy(string))
        return
    for i in range(index, len(array)):
        if i in visited:
            continue
        string.append(array[i])
        visited.append(i)
        combination(array, length, i + 1)
        string.pop()
        visited.pop()

vowels = ('a', 'e', 'i', 'o', 'u')
l, c = map(int, input().split(' '))

array = input().split(' ')
array.sort()

combination(array, l, 0)

for password in result:
    count = 0
    for i in password:
        if i in vowels:
            count += 1
    
    if count >= 1 and count <= l - 2:
        print(''.join(password))