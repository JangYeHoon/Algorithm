# https://school.programmers.co.kr/learn/courses/30/lessons/72410

def solution(new_id):
    # 모든 대문자를 소문자로 치환
    new_id = new_id.lower()
    # 알파벳 소문자, 숫자, -, _, .를 제외한 모든 문자 제거
    for c in new_id:
        if 'a' <= c <= 'z':
            continue
        if c.isdigit():
            continue
        if c in ['-', '_', '.']:
            continue
        new_id = new_id.replace(c, '')
    # 마침표 2번 이상 하나로 치환
    while '..' in new_id:
        new_id = new_id.replace('..', '.')
    # 마침표 처음이나 끝이면 제거
    if new_id[0] == '.':
        new_id = new_id[1:] if len(new_id) > 1 else '.'
    if new_id[-1] == '.':
        new_id = new_id[:-1]
    # 빈 문자열이면 a 추가
    if len(new_id) == 0:
        new_id = 'a'
    # 길이가 16자 이상이면 15개 문자제외하고 나머지 삭제 후 마지막 마침표 삭제
    if len(new_id) >= 16:
        new_id = new_id[:15]
    if new_id[-1] == '.':
        new_id = new_id[:-1]
    # 길이가 2자 이하라면 마지막 문자를 추가해서 길이 3으로 만듬
    if len(new_id) <= 2:
        while len(new_id) < 3:
            new_id += new_id[-1]
    return new_id