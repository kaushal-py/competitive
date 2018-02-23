import math

t = int(input())
for _ in range(t):
    N, K, S = map(int, input().split())

    choc_req = K*S
    days_req = math.ceil(choc_req/N)
    days_last = S - (S//7)

    if days_req <= days_last:
        print(days_req)
    else:
        print(-1)