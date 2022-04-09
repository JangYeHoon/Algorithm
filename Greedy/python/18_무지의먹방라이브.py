# 이것이 취업을 위한 코딩테스트다 315p
# https://programmers.co.kr/learn/courses/30/lessons/42891
# 2

import heapq

def solution(food_times, k):
    if sum(food_times) <= k:
        return -1
    
    pq = []
    for i in range(len(food_times)):
        heapq.heappush(pq, (food_times[i], i + 1))
    
    sum_value = 0
    previous = 0
    length = len(food_times)

    while sum_value + ((pq[0][0] - previous) * length) <= k:
        now = heapq.heappop(pq)[0]
        sum_value += (now - previous) * length
        length -= 1
        previous = now
    
    answer = sorted(pq, key=lambda x: x[1])
    return answer[(k - sum_value) % length][1]