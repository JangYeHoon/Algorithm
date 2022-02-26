# 자물쇠와열쇠, 뱀

def rotate90(key):
    m = len(key)
    new_key = [[0] * m for _ in range(m)]
    for i in range(m):
        for j in range(m):
            new_key[j][m - i - 1] = key[i][j]
    return new_key

def lock_chk(lock):
    n = len(lock) // 3
    for i in range(n, n * 2):
        for j in range(n, n * 2):
            if lock[i][j] != 1:
                return False
    return True

def solution(key, lock):
    n = len(lock)
    m = len(key)
    new_lock = [[0] * (n * 3) for _ in range(n * 3)]
    for i in range(n):
        for j in range(n):
            new_lock[i + n][j + n] = lock[i][j]
    
    for x in range(n * 2):
        for y in range(n * 2):
            for _ in range(4):
                key = rotate90(key)
                for i in range(m):
                    for j in range(m):
                        new_lock[x + i][y + j] += key[i][j]
                if lock_chk(new_lock):
                    return True
                for i in range(m):
                    for j in range(m):
                        new_lock[x + i][y + j] -= key[i][j]
    return False

solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]], [[1, 1, 1], [1, 1, 0], [1, 0, 1]])