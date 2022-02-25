# 
# https://programmers.co.kr/learn/courses/30/lessons/60061
# 

def pillar_check(pillar_matrix, panner_matrix, x, y):
    if y == 0 or panner_matrix[y][x] > 0 or pillar_matrix == 1:
        return True
    return False

def panner_check(pillar_matrix, panner_matrix, x, y):
    if pillar_matrix[y][x] > 0 or pillar_matrix[y + 1][x] > 0:
        return True
    if panner_matrix[y][x] > 0 and panner_matrix[y + 1][x] > 0:
        return True
    return False

def solution(n, build_frame):
    answer = [[]]
    pillar_matrix = [[0] * (n + 1) for _ in range(n + 1)]
    panner_matrix = [[0] * (n + 1) for _ in range(n + 1)]
    for x, y, a, b in build_frame:
        if a == 1:
            if b == 1:
                if pillar_check(pillar_matrix, panner_matrix, x, y):
                    pillar_matrix[y][x] += 1
                    pillar_matrix[y][x + 1] += 1
            else:
                if (panner_check(pillar_matrix, panner_matrix, x, y) and 
                    panner_check(pillar_matrix, panner_matrix, x, y - 1) and 
                    panner_check(pillar_matrix, panner_matrix, x + 1, y) and
                    panner_check(pillar_matrix, panner_matrix, x + 1, y - 1) and
                    pillar_check(pillar_matrix, panner_matrix, x + 1, y)):
                    pillar_matrix[y][x] -= 1
                    pillar_matrix[y][x + 1] -= 1
        elif a == 0:
            if b == 1:
                if panner_check(pillar_matrix, panner_matrix, x, y):
                    panner_matrix[y][x] += 1
                    panner_matrix[y + 1][x] += 1
            else:
                if (panner_check(pillar_matrix, panner_matrix, x, y - 1) and 
                    panner_check(pillar_matrix, panner_matrix, x, y + 1) and
                    pillar_check(pillar_matrix, panner_matrix, x, y + 1) and
                    pillar_check(pillar_matrix, panner_matrix, x, y)):
                    panner_matrix[y][x] -= 1
                    panner_matrix[y + 1][x] -= 1
    return answer

solution(5, [[1,0,0,1],[1,1,1,1],[2,1,0,1],[2,2,1,1],[5,0,0,1],[5,1,0,1],[4,2,1,1],[3,2,1,1]])