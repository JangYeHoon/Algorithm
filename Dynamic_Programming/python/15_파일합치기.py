# fast campus 강의
# https://www.acmicpc.net/problem/11066
# 2

def process():
    N, A = int(input()), [0] + list(map(int, input().split()))
    # S[i]는 1번부터 i번까지의 누적합
    S = [0 for _ in range(N + 1)]
    for i in range(1, N + 1):
        S[i] = S[i - 1] + A[i]
    print(S)
    # DP[i][j] = i에서 j까지 합하는데 필요한 최소 비용
    # DP[i][k] + DP[k + 1][j] + sum(array[i] ~ array[j])
    DP = [[0 for i in range(N + 1)] for i in range(N + 1)]
    for i in range(2, N + 1): # 부분파일의 길이
        for j in range(1, N + 2 - i): # 시작점
            DP[j][j + i - 1]= min(DP[j][j + k] + DP[j + k + 1][j + i - 1] for k in range(i - 1)) + (S[j + i - 1] - S[j - 1])
            for r in DP:
                for c in r:
                    print(c, end='\t')
                print()
            print()
    
    print(DP[1][N])

for _ in range(int(input())):
    process()