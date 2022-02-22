# 이것이 취업을 위한 코딩테스트다 325p
# https://programmers.co.kr/learn/courses/30/lessons/60059?language=python3
# 1

def rotate90(key):
    M = len(key)
    rotateKey = [[0] * M for _ in range(M)]
    for i in range(M):
        for j in range(M):
            rotateKey[j][M - i - 1] = key[i][j]
    return rotateKey

def check(lock):
    N = len(lock) // 3
    for i in range(N, N * 2):
        for j in range(N, N * 2):
            if lock[i][j] != 1:
                return False
    return True

def solution(key, lock):
    answer = True
    N = len(lock)
    M = len(key)
    new_lock = [[0] * (N * 3) for _ in range(N * 3)]
    for i in range(N):
        for j in range(N):
            new_lock[i + N][j + N] = lock[i][j]

    for x in range(N * 2):
        for y in range(N * 2):
            for _ in range(4):
                key = rotate90(key)
                for i in range(M):
                    for j in range(M):
                        new_lock[x + i][y + j] += key[i][j]
                
                if check(new_lock):
                    return True
                
                for i in range(M):
                    for j in range(M):
                        new_lock[x + i][y + j] -= key[i][j]
    answer = False
    return answer