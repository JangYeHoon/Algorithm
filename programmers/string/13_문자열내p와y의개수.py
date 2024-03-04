def solution(s):
    answer = True
    cnt = 0
    for c in s.lower():
        if c == 'p':
            cnt += 1
        elif c == 'y':
            cnt -= 1

    return True if cnt == 0 else False