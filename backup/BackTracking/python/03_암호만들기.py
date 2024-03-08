# fast campus 강의
# https://www.acmicpc.net/problem/1759
# 2

from itertools import combinations

L, C = map(int, input().split())
alphabet = list(input().split(' '))
alphabet.sort()

vowels = ['a', 'e', 'i', 'o', 'u']
result = []
for passwd in combinations(alphabet, L):
    vowles_cnt = 0
    for v in vowels:
        vowles_cnt += passwd.count(v)
    if vowles_cnt > 0 and len(passwd) - vowles_cnt > 1:
        result.append(''.join(passwd))

for r in result:
    print(r)
