t = int(input())

for i in range(t):

    n, r = map(int, input().split())

    arr = [int(x) for x in input().split()]

    maxR = -1
    minR = -1

    flag = True

    for k in arr:
        if k < r:
            if minR == -1:
                minR = k
            elif k < minR:
                flag = False
                break
            else:
                minR = k
        if k > r:
            if maxR == -1:
                maxR = k
            elif k > maxR:
                flag = False
                break
            else:
                maxR = k
    
    if flag:
        print("YES")
    else:
        print("NO")
