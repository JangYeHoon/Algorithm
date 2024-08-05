from collections import deque

mx, my = [-1, 1, 0, 0], [0, 0, -1, 1]

def solution(maps):
    answer = 0
    n = len(maps) - 1
    m = len(maps[0]) - 1
    
    q = deque()
    q.append((0, 0))
    while q:
        px, py = q.popleft()
        if px == n and py == m:
            return maps[n][m]
        
        for i in range(4):
            nx = px + mx[i]
            ny = py + my[i]
            
            if nx < 0 or nx > n or ny < 0 or ny > m:
                continue
            if maps[nx][ny] == 1:
                maps[nx][ny] = maps[px][py] + 1
                q.append((nx, ny))
    return -1