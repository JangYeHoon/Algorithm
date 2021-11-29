# fast campus 강의
# https://www.acmicpc.net/problem/10930
# 1

import hashlib

s = input()

result = hashlib.sha256(s.encode())
print(result.hexdigest())