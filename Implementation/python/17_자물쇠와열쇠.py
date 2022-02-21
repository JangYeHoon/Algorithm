# 이것이 취업을 위한 코딩테스트다 325p
# https://programmers.co.kr/learn/courses/30/lessons/60059?language=python3
# 0

from copy import deepcopy

def rotate90(key):
    rotateKey = key
    for i in range(len(key)):
        for j in range(len(key)):
            rotateKey[i][j] = key[j][len(key) - i - 1]
    return rotateKey

def check(x, y, lock, key):
    temp_lock = deepcopy(lock)
    for i in range(x, len(key) + x):
        for j in range(y, len(key) + y):
            if key[i - x][j - y] == 1:
                temp_lock[i][j] = 1

    for i in range(1, len(lock) - 1):
        for j in range(1, len(lock) - 1):
            if temp_lock[i][j] == 0:
                return False
    return True

def solution(key, lock):
    answer = True
    new_lock = [[0] * (len(lock) + 2) for _ in range(len(lock) + 2)]
    for i in range(1, len(new_lock) - 1):
        for j in range(1, len(new_lock) - 1):
            new_lock[i][j] = lock[i - 1][j - 1]

    for i in range(len(new_lock)):
        for j in range(len(new_lock)):
            for _ in range(4):
                key = rotate90(key)
                if check(i, j, new_lock, key):
                   return answer
    answer = False
    return answer