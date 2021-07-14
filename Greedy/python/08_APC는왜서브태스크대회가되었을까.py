N, L, K = map(int, input().split())

exam_list = []
for i in range(N):
    easy, hard = map(int, input().split())
    exam_list.append([easy, hard])
exam_list.sort(key=lambda x:x[1])

score = 0
time = 0
for i in range(N):
    if time == K:
        break
    if L >= exam_list[i][1]:
        score += 140
        time += 1
    elif L >= exam_list[i][0]:
        score += 100
        time += 1

print(score)