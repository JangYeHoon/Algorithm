# fast campus 강의
# https://www.acmicpc.net/problem/1543
# 2

document = input()
word = input()
idx = 0
result = 0

while len(document) - idx >= len(word):
    if document[idx:idx + len(word)] == word:
        result += 1
        idx += len(word)
    else:
        idx += 1

print(result)