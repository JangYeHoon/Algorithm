def sum_row(row):
    return sum(row)

def sum_column(matrix, col_index):
    return sum(row[col_index] for row in matrix)

def solution(friends, gifts):
    length = len(friends)
    answer = [0] * length
    gift_dict = {}
    for i in range(length):
        gift_dict[friends[i]] = i
    
    gift_table = list([0] * length for i in range(length))
    for gift in gifts:
        a, b = gift.split(' ')
        gift_table[gift_dict[a]][gift_dict[b]] += 1

    index_table = [0] * length
    send = [sum_row(row) for row in gift_table]
    recieve = [sum_column(gift_table, col) for col in range(length)]
    for i in range(length):
        index_table[i] = send[i] - recieve[i]
    
    for i in range(length):
        for j in range(i, length):
            if (gift_table[i][j] == 0 and gift_table[j][i] == 0) or gift_table[i][j] == gift_table[j][i]:
                if index_table[i] > index_table[j]:
                    answer[i] += 1
                elif index_table[i] < index_table[j]:
                    answer[j] += 1
            else:
                if gift_table[i][j] > gift_table[j][i]:
                    answer[i] += 1
                else:
                    answer[j] += 1
    return max(answer)

print(solution(["muzi", "ryan", "frodo", "neo"], ["muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"]))