def solution(n, lost, reserve):
    students = [1] * (n + 2)
    students[0], students[-1] = 0, 0
    for i in lost:
        students[i] -= 1
    for i in reserve:
        students[i] += 1
        
    for i in range(1, len(students)-1):
        if students[i] == 0 and students[i-1] == 2:
            students[i-1] -= 1
            students[i] += 1 
        elif students[i] == 0 and students[i+1] == 2:
            students[i+1] -= 1
            students[i] += 1
    answer = 0
    for i in students:
        if i > 0:
            answer += 1
    return answer