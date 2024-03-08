# 이것이 취업을 위한 코딩테스트다 180p
# 2

N = int(input())

arr = []
for _ in range(N):
    name, score = input().split()
    arr.append((name, int(score)))
arr.sort(key=lambda x:x[1])

for i in arr:
    print(i[0], end=' ')