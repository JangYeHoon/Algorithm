# https://school.programmers.co.kr/learn/courses/30/lessons/92334?language=python3

def solution(id_list, report, k):
    answer = []
    report = list(set(report))
    report_dic = {}
    report_cnt = {}
    for id in id_list:
        report_dic[id] = []
        report_cnt[id] = 0

    for r in report:
        a, b = r.split(' ')
        report_dic[a].append(b)
        report_cnt[b] += 1
    
    for id in id_list:
        cnt = 0
        for r in report_dic[id]:
            if report_cnt[r] >= k:
                cnt += 1
        answer.append(cnt)
    return answer

print(solution(["muzi", "frodo", "apeach", "neo"], ["muzi frodo", "muzi frodo", "apeach frodo","frodo neo","muzi neo","apeach muzi"], 2))