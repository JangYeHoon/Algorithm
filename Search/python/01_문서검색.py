string = input()
word = input()

result = 0
for i in range(len(string)):
    temp = 0
    k = i
    while k < len(string):
        if word == string[k:k+len(word)]:
            temp += 1
            k += len(word)
        else:
            k += 1
    result = max(result, temp)

print(result)