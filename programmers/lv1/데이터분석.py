def solution(data, ext, val_ext, sort_by):
    answer = []
    order = ["code", "date", "maximum", "remain"]
    for d in data:
        if d[order.index(ext)] < val_ext:
            answer.append(d)
    return sorted(answer, key=lambda x: x[order.index(sort_by)])