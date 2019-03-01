t = int(input())

alphabets = "abcdefghijklmnopqrstuvwxyz"

for i in range(t):
    n, a = map(int, input().split())
    if a > n:
        output = alphabets[0:n]
        length = 1
    elif a > 2:
        output = alphabets[0:a]*(n//a) + alphabets[0:(n%a)]
        length = 1
    elif a == 2:
        if n == 1:
            output = "a"
            length = 1
        elif n == 2:
            output = "ab"
            length = 1
        elif n == 3:
            output = "aab"
            length = 2
        elif n == 4:
            output = "aabb"
            length = 2
        elif n == 5:
            output = "aaabb"
            length = 2
        elif n == 6:
            output = "aababb"
            length = 3
        elif n == 7:
            output = "aaababb"
            length = 3
        elif n == 8:
            output = "aaababbb"
            length = 3
        elif n == 9:
            output = "abaabbaba"
            length = 4
        elif n == 10:
            output = "abaabbabaa"
            length = 4
        else:
            if(n%2 == 0):
                length = (n//2 -1)
                output = ("a"*(n//2 - 1)) + "ba" + ("b"*(n//2 - 1))
            else:
                length = (n//2)
                output = ("a"*(n//2 - 1)) + "ba" + ("b"*(n//2))
    
    print(length, output)
