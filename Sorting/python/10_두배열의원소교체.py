# 이것이 취업을 위한 코딩테스트다 182p
# 2

N, K = map(int, input().split())
A = sorted(list(map(int, input().split())))
B = sorted(list(map(int, input().split())), reverse=True)

for i in range(K):
    if A[i] < B[i]:
        A[i], B[i] = B[i], A[i]
    else:
        break
print(sum(A))