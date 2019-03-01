t = int(input())

for i in range(t):

    config = input()

    j=0
    count_A = 0
    count_B = 0

    while j<len(config):

        if config[j] == '.':
            if j!=0:
                currConquor = config[j-1]
                if currConquor != '.':
                    curr_j = j
                    while(j < len(config)-1 and config[j] == '.'):
                        j+=1
                    if(config[j] == currConquor):
                        if(currConquor == 'A'):
                            count_A += j-curr_j
                        else:
                            count_B += j-curr_j
        if config[j] == 'A':
            count_A+=1
        if config[j] == 'B':
            count_B+=1
        j+=1
    
    print(count_A, count_B)
