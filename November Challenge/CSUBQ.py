n, q, L, R = map(int, input().split())

arr = [0]*n

table = []

for k in range(n+3):
    table.append([0]*5)

for i in range(q):
    
    mode, x, y = map(int, input().split())

    if mode == 1:
        flag = False

        if y>=L and y<=R:
            newElement = 1
            flag = True
        elif y<L or y>R:
            newElement = 0
            flag = True

        if flag:
            for q in range(x-1, n):
                for p in range(x-1, -1, -1):
                    if (p,q) == (x-1, x-1):
                        if newElement == 0:
                            table[p][q] = 0
                        else:
                            table[p][q] += 1
                    elif p == x-1 and newElement == 1:
                        table[p][q] = table[p][q-1] + 1
                    elif y<L and table[p][q-1] != 0:
                        pass
                    else:
                        table[p][q] = table[p][q-1] + table[p+1][q] - table[p+1][q-1]
        arr[x-1] = y
        for row in table:
            print(row)
        print()

    if mode == 2:
        print(table[x-1][y-1])