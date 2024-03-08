# https://school.programmers.co.kr/learn/courses/30/lessons/64061?language=python3

def solution(board, moves):
    answer = 0
    bucket = []
    for move in moves:
        for i in range(len(board)):
            if board[i][move - 1] != 0:
                if len(bucket) > 0 and bucket[-1] == board[i][move - 1]:
                    answer += 2
                    bucket = bucket[:-1]
                else:
                    bucket.append(board[i][move - 1])
                board[i][move - 1] = 0
                break
    return answer
