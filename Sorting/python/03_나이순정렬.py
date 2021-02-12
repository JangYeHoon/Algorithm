N = int(input())

person = []
for _ in range(N):
    age, name = input().split(' ')
    person.append([int(age), name])

result = sorted(person, key=lambda x:x[0])

for i in range(len(result)):
    print("{} {}".format(result[i][0], result[i][1]))