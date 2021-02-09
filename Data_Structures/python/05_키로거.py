test_case = int(input())

for _ in range(0, test_case):
    s = input()
    stack = []
    result = []
    for c in s:
        if c == "<" and len(stack) > 0:
            stack.pop()
        elif c == ">" and len(result) > len(stack):
            stack.append(1)
        elif c == "-" and len(result) > 0:
            del result[len(stack) - 1]
            stack.pop()
        elif c != "<" and c != ">" and c != "-":
            result.insert(len(stack), c)
            stack.append(1)
    print(''.join(result))