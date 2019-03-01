memory = [-1]*1000000

# Only 1 triangle case
memory[0] = 1

# Calculate triangles
'''
Logic :: Triangles in nth case = 3*[(n-1)th case] + 2
'''
for i in range(1, 1000000):
    memory[i] = memory[i-1]*3 + 2
    print(i)
# def calcTriangle(n):
#     if memory[n] == -1:
#         memory[n] = calcTriangle(n-1)*3 + 2
#     return memory[n]

q = int(input())
for _ in range(q):
    n = int(input())
    ans = (memory[n] % (1000000000+7))
    print(ans)