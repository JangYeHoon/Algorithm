def solution(keymap, targets):
    answer = [0] * len(targets)
    for j, target in enumerate(targets):
        for i in target:
            idx = 99999
            for key in keymap:
                if key.find(i) == -1:
                    continue
                idx = min(idx, key.find(i) + 1)
            if idx == 99999:
                answer[j] = -1
                break
            else:
                answer[j] += idx
    return answer