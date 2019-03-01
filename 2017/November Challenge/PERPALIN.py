def findPattern(a):
    if a == 4:
        return "abba"
    elif a%2 == 0:
        return findPattern(a//2) * 2
    else:
        return (("ab" * (a//2)) + "a")

t = int(input())

for i in range(t):

    n, p = map(int, input().split())

    if p == 1 or p == 2:
        output = "impossible"

    elif (n%p) != 0:
        output = "impossible"
    else:
        output = findPattern(p) * (n//p)
    
    print(output)