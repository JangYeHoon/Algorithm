# https://school.programmers.co.kr/learn/courses/30/lessons/178871

def solution(players, callings):
    player_dict = {}
    for i in range(len(players)):
        player_dict[players[i]] = i

    for call in callings:
        idx = player_dict[call]
        if idx != 0:
            player_dict[players[idx]] -= 1
            player_dict[players[idx-1]] += 1
            players[idx - 1], players[idx] = players[idx], players[idx - 1]
    return players
