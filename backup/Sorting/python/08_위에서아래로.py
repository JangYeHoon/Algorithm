# 이것이 취업을 위한 코딩테스트다 178p
# 2

N = int(input())

arr = []
for _ in range(N):
    tmp = int(input())
    arr.append(tmp)
arr.sort(reverse=True)

for i in arr:
    print(i, end=' ')