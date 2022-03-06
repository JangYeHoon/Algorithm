# 이것이 취업을 위한 코딩테스트다 335p
# https://programmers.co.kr/learn/courses/30/lessons/60062
# 2

from itertools import permutations

def solution(n, weak, dist):
    answer = len(dist) + 1
    weak_length = len(weak)
    for i in range(weak_length):
        weak.append(weak[i] + n)
    
    for start in range(weak_length):
        for friends in list(permutations(dist, len(dist))):
            count = 1
            position = weak[start] + friends[count - 1]
            for i in range(start, start + weak_length):
                if position < weak[i]:
                    count += 1
                    if count > len(dist):
                        break
                    position = weak[i] + friends[count - 1]
            answer = min(answer, count)
    if answer > len(dist):
        return -1
    return answer

print(solution(12, [1, 5, 6, 10], [1, 2, 3, 4]))