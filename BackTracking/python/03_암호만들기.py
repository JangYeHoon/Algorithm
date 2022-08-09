# fast campus 강의
# https://www.acmicpc.net/problem/1759
# 1

from itertools import combinations

l, c = map(int, input().split())
alpabet = list(input().split(' '))

alpabet.sort()

vowels = ['a', 'e', 'i', 'o', 'u']
result = []
for s in combinations(alpabet, l):
    vowels_count = 0
    for v in vowels:
        vowels_count += s.count(v)
    if vowels_count > 0 and l - vowels_count > 1:
        result.append(''.join(s))

for r in result:
    print(r)
