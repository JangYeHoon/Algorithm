def solution(arr1, arr2):
    answer = []
    for i in range(len(arr1)):
        answer.append(list(arr1[i][j] + arr2[i][j] for j in range(len(arr1[0]))))
    return answer