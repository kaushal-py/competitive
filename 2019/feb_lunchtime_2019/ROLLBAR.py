class State:

    up=True
    loc= [(1,1)]

    def __init__(self, up, loc):
        self.up=up
        self.loc = loc
        self.assertpos()
    

    def assertpos(self):
        if self.up:
            assert len(self.loc) == 1
        else:
            assert len(self.loc) == 2


def next_states(s, grid):

    states = []

    if s.up:
        (x,y) = s.loc[0]
        
        if(grid[x+1][y] and grid[x+2][y]):
            ns = State(up=False, loc=[(x+1,y),(x+2,y)])
            states.append(ns)
        
        if(grid[x-1][y] and grid[x-2][y]):
            ns = State(up=False, loc=[(x-1,y),(x-2,y)])
            states.append(ns)
        
        if(grid[x][y+1] and grid[x][y+2]):
            ns = State(up=False, loc=[(x,y+1),(x,y+2)])
            states.append(ns)
        
        if(grid[x][y-1] and grid[x][y-2]):
            ns = State(up=False, loc=[(x,y-1),(x,y-2)])
            states.append(ns)
    
    else:
        (x1, y1) = s.loc[0]
        (x2, y2) = s.loc[1]
        # print(x1, y1, x2, y2)

        if (y1 == y2):

            if(grid[x2+1][y1]):
                ns = State(up=True, loc=[(x2+1,y1)])
                states.append(ns)
            
            if(grid[x1-1][y1]):
                ns = State(up=True, loc=[(x1-1,y1)])
                states.append(ns)
        

            if(grid[x1][y1+1] and grid[x2][y2+1]):
                ns= State(up=False, loc=[(x1,y1+1),(x2, y2+1)])
                states.append(ns)

            if(grid[x1][y1-1] and grid[x2][y2-1]):
                ns= State(up=False, loc=[(x1,y1-1),(x2, y2-1)])
                states.append(ns)

        elif(x1 == x2):

            if(grid[x1][y2+1]):
                ns = State(up=True, loc=[(x1,y2+1)])
                states.append(ns)
            
            if(grid[x1][y1-1]):
                ns = State(up=True, loc=[(x1,y1-1)])
                states.append(ns)
        

            if(grid[x1+1][y1] and grid[x2+1][y2]):
                ns= State(up=False, loc=[(x1+1,y1),(x2+1, y2)])
                states.append(ns)

            if(grid[x1-1][y1] and grid[x2-1][y2]):
                ns= State(up=False, loc=[(x1-1,y1),(x2-1, y2)])
                states.append(ns)
    
    return states
  

# s1= State(up=False, loc=[(1,1),(1,2)])

t=int(input())

for i in range(t):

    m,n = map(int, input().split())
    x,y = map(int, input().split())

    m=m+4
    n=n+4

    grid = [[False for i in range(n)] for j in range(m)]

    for j in range(2,m-2):
        s=input()
        i=2
        for c in s: 
            if c=='1':
                grid[j][i] = True
            else:
                grid[j][i] = False
            i+=1

print(grid)
s1 = State(up=True, loc=[(x+2,y+2)])

queue = []
queue.append(s1)
visited = []

def compare_states(s1, s2):
    return s1.loc == s2.loc

while len(queue) != 0:
    
    cur = queue[0]
    del queue[0]

    visited.append(cur)


    for state in next_states(s1, grid):
        is_visited = False
        for v in visited:
            if compare_states(v, state):
                is_visited=True
                break
            
        if not is_visited:
            queue.append(state)