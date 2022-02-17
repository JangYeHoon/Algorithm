# 이것이 취업을 위한 코딩테스트다.
# 
# 1

S = list(input())
result = []
cnt = 0

for c in S:
    if 'A' <= c and c <= 'Z':
        result.append(c)
    else:
        cnt += int(c)
result.sort()
if cnt != 0:
    result.append(str(cnt))
print(''.join(result))