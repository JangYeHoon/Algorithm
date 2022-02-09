# 주사위세개, 주사위네개, 두개의손

ML, MR, TL, TR = ('SPR'.index(i) for i in input().split())

if (ML == MR and (ML + 2) % 3 in [TL, TR]):
    print("TK")
elif (TL == TR and (TL + 2) % 3 in [ML, MR]):
    print("MS")
else:
    print("?")