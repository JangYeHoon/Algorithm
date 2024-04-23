def solution(participant, completion):
    answer = ''
    participant = sorted(participant)
    completion = sorted(completion)
    for i in range(len(participant)-1):
        if participant[i] != completion[i]:
            return participant[i]
    return participant[-1]