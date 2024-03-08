# 이것이 취업을 위한 코딩테스트다
# https://school.programmers.co.kr/learn/courses/30/lessons/60060
# 1

from bisect import bisect_left, bisect_right

def count_by_range(arr, left, right):
    left_idx = bisect_left(arr, left)
    right_idx = bisect_right(arr, right)
    return right_idx - left_idx

arr = [[] for _ in range(10001)]
reversed_arr = [[] for _ in range(10001)]

def solution(words, queries):
    answer = []
    for word in words:
        arr[len(word)].append(word)
        reversed_arr[len(word)].append(word[::-1])
    
    for i in range(10001):
        arr[i].sort()
        reversed_arr[i].sort()

    for query in queries:
        if query[0] != '?':
            res = count_by_range(arr[len(query)], query.replace('?', 'a'), query.replace('?', 'z'))
        else:
            res = count_by_range(reversed_arr[len(query)], query[::-1].replace('?', 'a'), query[::-1].replace('?', 'z'))
        answer.append(res)
    return answer

print(solution(["frodo", "front", "frost", "frozen", "frame", "kakao"], ["fro??", "????o", "fr???", "fro???", "pro?"]))