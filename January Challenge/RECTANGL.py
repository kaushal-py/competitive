t = int(input())

for _ in range(t):

    sides = [int(x) for x in input().split()]

    sides.sort()

    if sides[0] == sides[1] and sides[2] == sides[3]:
        print("YES")
    
    else:
        print("NO")
