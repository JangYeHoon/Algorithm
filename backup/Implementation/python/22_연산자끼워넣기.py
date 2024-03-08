# 이것이 취업을 위한 코딩테스트다 349p
# https://www.acmicpc.net/problem/14888
# 2

from itertools import permutations

N = int(input())
A = list(map(int, input().split()))
op_list = []
op_num = list(map(int, input().split()))
for i in range(4):
    for j in range(op_num[i]):
        op_list.append(i)

min_value = 1e9
max_value = -1e9
for op in list(permutations(op_list)):
    result = A[0]
    for i in range(1, len(A)):
        if op[i - 1] == 0:
            result += A[i]
        elif op[i - 1] == 1:
            result -= A[i]
        elif op[i - 1] == 2:
            result *= A[i]
        elif op[i - 1] == 3:
            result /= A[i]
            result = int(result)
    min_value = min(min_value, result)
    max_value = max(max_value, result)
print(max_value)
print(min_value)