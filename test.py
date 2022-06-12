# 0만들기

import copy


def recursive(lst):
    if len(lst) == N - 1:
        op_list.append(copy.deepcopy(lst))
        return

    lst.append(' ')
    recursive(lst)
    lst.pop()

    lst.append('+')
    recursive(lst)
    lst.pop()

    lst.append('-')
    recursive(lst)
    lst.pop()


for _ in range(int(input())):
    N = int(input())
    op_list = []
    recursive([])

    for op in op_list:
        result = ""
        for i in range(len(op)):
            result += str(i + 1) + op[i]
        result += str(N)

        if eval(result.replace(' ', '')) == 0:
            print(result)
    print()
