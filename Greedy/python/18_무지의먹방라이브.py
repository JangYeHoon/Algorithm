# 이것이 취업을 위한 코딩테스트다 315p
# https://programmers.co.kr/learn/courses/30/lessons/42891
# 0

def solution(food_times, k):
    answer = 0
    idx = 0
    time = 1
    while True:
        if len(set(food_times)) == 0 and food_times[0] == 0:
            break
        if food_times[idx] == 0:
            idx = (idx + 1) % len(food_times)
            continue
        if time == k:
            answer = idx - 1
            break
        food_times[idx] -= 1
        idx = (idx + 1) % len(food_times)
        time += 1
    return answer