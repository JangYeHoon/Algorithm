# 문제집(c++), 유기농배추

import heapq

N, M = map(int, input().split())
arr = [[] for _ in range(N + 1)]
first_exam = [0] * (N + 1)
for _ in range(M):
    a, b = map(int, input().split())
    first_exam[b] += 1
    arr[a].append(b)

exam_list = []
for i in range(1, N + 1):
    if first_exam[i] == 0:
        heapq.heappush(exam_list, i)

result = []
while len(result) != N:
    exam = heapq.heappop(exam_list)
    result.append(exam)
    for i in range(len(arr[exam])):
        first_exam[arr[exam][i]] -= 1
        if first_exam[arr[exam][i]] == 0:
            heapq.heappush(exam_list, arr[exam][i])
for a in result:
    print(a, end = " ")