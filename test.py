# 키로거, SHA-265(python), 

import hashlib

s = input()
result = hashlib.sha256(s.encode()).hexdigest()
print(result)