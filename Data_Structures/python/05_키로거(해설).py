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
    right_stack.reverse()
    result = left_stack + right_stack
    print(''.join(result))