t = int(input())

for _ in range(t):
    
    n, p = map(int, input().split())
    
    ez = 0
    hard = 0
    
    pi_arr = [int(x) for x in input().split()]
        
    for pi in pi_arr:
        if pi >= p//2:
            ez+=1
        elif pi <= p/10:
            hard+=1
    
    if ez==1 and hard == 2:
        print("yes")
    else:
        print("no")