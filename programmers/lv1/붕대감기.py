def solution(bandage, health, attacks):
    answer = health
    success = 0
    for i in range(1, attacks[-1][0] + 1):
        if attacks[0][0] == i:
            answer -= attacks[0][1]
            attacks.pop(0)
            success = 0
        else:
            success += 1
            if success == bandage[0]:
                answer += bandage[2]
                success = 0
            answer += bandage[1]
            if answer > health: answer = health
        if answer <= 0:
            return -1
        if len(attacks) == 0:
            break
    return answer