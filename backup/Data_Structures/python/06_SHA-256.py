# fast campus 강의
# https://www.acmicpc.net/problem/10930
# 2

import hashlib

s = input()
result = hashlib.sha256(s.encode()).hexdigest()
print(result)