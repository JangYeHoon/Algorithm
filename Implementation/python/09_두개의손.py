# fast campus 강의
# https://www.acmicpc.net/problem/16675
# 1

ML, MR, TL, TR = ('SPR'.index(i) for i in input().split())

if ML == MR and (ML + 2) % 3 in [TL, TR]:
    print("TK")
elif TL == TR and (TL + 2) % 3 in [ML, MR]:
    print("MS")
else:
    print("?")