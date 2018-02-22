t = int(input())

for _ in range(t):

    n = int(input())

    numbers = []

    for k in range(n):
        seq = [int(x) for x in input().split()]
        numbers.append(seq)
    
    numbers.reverse()

    max_num = max(numbers[0]) + 1
    sum_num = 0

    for seq in numbers:

        try:
            max_num = max([x for x in seq if x < max_num])
        except ValueError:
            sum_num = -1
            break
        
        sum_num += max_num
    
    print(sum_num)

