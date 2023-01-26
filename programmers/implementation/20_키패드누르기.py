# https://school.programmers.co.kr/learn/courses/30/lessons/67256

def solution(numbers, hand):
    answer = ''
    left_pos = [3, 0]
    right_pos = [3, 2]
    number_dict = {1:[0,0], 2:[0,1], 3:[0,2],
                 4:[1,0], 5:[1,1], 6:[1,2],
                 7:[2,0], 8:[2,1], 9:[2,2],
                 0:[3,1]}
    for number in numbers:
        if number in [1, 4, 7]:
            answer += 'L'
            left_pos = number_dict[number]
        elif number in [3, 6, 9]:
            answer += 'R'
            right_pos = number_dict[number]
        else:
            right_len = abs(right_pos[0] - number_dict[number][0]) + abs(right_pos[1] - number_dict[number][1])
            left_len = abs(left_pos[0] - number_dict[number][0]) + abs(left_pos[1] - number_dict[number][1])
            if right_len == left_len:
                if hand == 'left':
                    answer += 'L'
                    left_pos = number_dict[number]
                else:
                    answer += 'R'
                    right_pos = number_dict[number]
            elif right_len < left_len:
                answer += 'R'
                right_pos = number_dict[number]
            else:
                answer += 'L'
                left_pos = number_dict[number]
    return answer