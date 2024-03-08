# fast campus 강의
# https://www.acmicpc.net/problem/7490
# 2

import copy


def recursive(array, n):
    if len(array) == n:
        op_list.append(copy.deepcopy(array))
        return

    array.append(' ')
    recursive(array, n)
    array.pop()

    array.append('+')
    recursive(array, n)
    array.pop()

    array.append('-')
    recursive(array, n)
    array.pop()


test_case = int(input())

for _ in range(test_case):
    N = int(input())
    op_list = []
    recursive([], N - 1)

    num = [i for i in range(1, N + 1)]

    for op in op_list:
        string = ""
        for i in range(N - 1):
            string += str(num[i]) + op[i]
        string += str(num[-1])

        if eval(string.replace(' ', '')) == 0:
            print(string)
    print()
