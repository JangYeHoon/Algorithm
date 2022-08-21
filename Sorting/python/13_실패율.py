# 이것이 취업을 위한 코딩테스트다
# https://school.programmers.co.kr/learn/courses/30/lessons/42889
# 2

def solution(N, stages):
    answer = []
    length = len(stages)
    fail_lst = []
    for i in range(1, N + 1):
        count = stages.count(i)

        if length == 0:
            fail = 0
        else:
            fail = count / length

        fail_lst.append((i, fail))
        length -= stages.count(i)
    fail_lst.sort(key=lambda x: (-x[1], x[0]))
    answer = [res[0] for res in fail_lst]
    return answer


print(solution(5, [2, 1, 2, 6, 2, 4, 3, 3]))
