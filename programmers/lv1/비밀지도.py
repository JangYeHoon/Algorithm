# def solution(n, arr1, arr2):
#     answer = []
#     for i,j in zip(arr1,arr2):
#         a12 = str(bin(i|j)[2:])
#         a12=a12.rjust(n,'0')
#         a12=a12.replace('1','#')
#         a12=a12.replace('0',' ')
#         answer.append(a12)
#     return answer

def solution(n, arr1, arr2):
    answer = []
    for i in range(len(arr1)):
        a = format(arr1[i], 'b')
        a = '0'*(len(arr1)-len(a)) + a
        b = format(arr2[i], 'b')
        b = '0'*(len(arr2)-len(b)) + b
        c = ''
        for j in range(len(arr1)):
            c += ' ' if a[j] == b[j] == '0' else '#'
        answer.append(c)
    return answer