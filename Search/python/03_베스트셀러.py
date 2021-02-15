N = int(input())
dic = {}

for _ in range(N):
    s = input()
    if dic.get(s) == None:
        dic[s] = 1
    else:
        dic[s] = dic[s] + 1
dic = sorted(dic.items(), key = lambda x:x[1], reverse=True)

max_value = dic[0][1]
result = []
for key in dic:
    if key[1] == max_value:
        result.append(key[0])
    else:
        break
result = sorted(result)
print(result[0])