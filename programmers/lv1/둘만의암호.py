def solution(s, skip, index):
    answer = ''
    alpabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
    for c in skip:
        alpabet.remove(c)
    for c in s:
        answer += alpabet[(alpabet.index(c) + index) % len(alpabet)]
    return answer