n, q, L, R = map(int, input().split())

arr = [0]*n

table = []
for k in range(n):
    table.append([0]*(k+1))

for i in range(q):
    
    mode, x, y = map(int, input().split())

    if mode == 1:
        arr[x-1] = y
        for p in range(0, x):
            for q in range(x-1, n):

                if q == p:
                    table[q][p] = arr[q]
                else:
                    table[q][p] = max(table[q-1][p], arr[q])

    if mode == 2:
        count = 0
        for p in range(x-1, y):
            for q in range(p , y):
                if table[q][p] >= L and table[q][p] <= R:
                    count+=1
        print(count)