# fast campus 강의
# https://www.acmicpc.net/problem/5397
# 1

test_case = int(input())

for _ in range(0, test_case):
    s = input()
    left_stack = []
    right_stack = []
    for c in s:
        if c == "<" and left_stack:
            right_stack.append(left_stack.pop())
        elif c == ">" and right_stack:
            left_stack.append(right_stack.pop())
        elif c == "-" and left_stack:
            left_stack.pop()
        elif c != "<" and c != ">" and c != "-":
            left_stack.append(c)

    left_stack.extend(reversed(right_stack))
    print(''.join(left_stack))