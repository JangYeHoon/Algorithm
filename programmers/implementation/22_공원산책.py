# https://school.programmers.co.kr/learn/courses/30/lessons/172928

def solution(park, routes):
    matrix = []
    px, py = 0, 0
    N, M = len(park), len(park[0])
    for i in range(len(park)):
        tmp = []
        for j in range(len(park[i])):
            tmp.append(park[i][j])
            if park[i][j] == 'S':
                px, py = i, j
        matrix.append(tmp)

    for route in routes:
        move = int(route[2])
        mx, my = px, py
        if route[0] == 'N':
            if px - move < 0:
                continue
            for _ in range(move):
                mx -= 1
                if matrix[mx][my] == 'X':
                    mx = px
                    break
        elif route[0] == 'S':
            if px + move >= N:
                continue
            for _ in range(move):
                mx += 1
                if matrix[mx][my] == 'X':
                    mx = px
                    break
        elif route[0] == 'W':
            if py - move < 0:
                continue
            for _ in range(move):
                my -= 1
                if matrix[mx][my] == 'X':
                    my = py
                    break
        else:
            if py + move >= M:
                continue
            for _ in range(move):
                my += 1
                if matrix[mx][my] == 'X':
                    my = py
                    break
        px, py = mx, my
    return [px, py]
