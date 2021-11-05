# fast campus 강의
# https://www.acmicpc.net/problem/2014
# 1

# 중복 제거 방법
# 입력 값 : 2, 3, 5, 7
# 2, 3, 5, 7을 각각 한번씩 곱했을 때 표
#   2       3       5       7
# 2 2*2     3*2(0)  5*2     7*2
# 3 2*3(0)  3*3     5*3(0)  7*3
# 5 2*5     3*5(0)  5*5     7*5(0)
# 7 2*7     3*7     5*7(0)  7*7
# 0으로 표시한 곳이 중복 구간인데 자기 자신으로 나눠지는 수의 위 아래임을 알 수 있음
# 따라서 곱한 값에 소수를 차례로 곱할 때 자기 자신으로 나눠지는 값까지만 곱을 추가하여 중복 제거
import heapq
import copy

K, N = map(int, input().split())
p_list = list(map(int, input().split()))

lst = copy.deepcopy(p_list)

heapq.heapify(lst)
index = 0
while index < N:
    mn = heapq.heappop(lst)
    index += 1
    for i in p_list:
        if mn * i < 2 ** 32:
            heapq.heappush(lst, mn * i)
            if mn % i == 0:
                break

print(mn)