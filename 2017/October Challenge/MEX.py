t = int(input())

for _ in range(t):
    n, k = map(int, input().split())

    s_arr = [int(x) for x in input().split()]

    # Set
    maxElement = max(s_arr)
    s_set = set(s_arr)
    i = 0
    while k >= 0:

        if i > maxElement:
            i += k
            break
        if i not in s_set:
            k -= 1    
        if k >= 0:
            i += 1
    
    print(i)


    # Sorting and iterating
    # s_arr.sort()
    # i = 0
    # pos = 0
    # sLen = len(s_arr)

    # while k >= 0:
    #     if pos < sLen:
    #         if i == s_arr[pos]:
    #             pos += 1
    #         elif i < s_arr[pos]:
    #             k -= 1
    #     else:
    #         i += k
    #         break
    #     if k >= 0:
    #         i += 1
    # print(i)
