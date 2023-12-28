import sys
import collections
input=sys.stdin.readline

x,y = map(int, input().split())
maze =[] 
check=[[0 for _ in range(y)]for _ in range(x)]

move=[[0,1],[0,-1],[-1,0],[1,0]]
def bfs():
  q_J = collections.deque()
  q_F = collections.deque()
  for i in range(x):
    temp = list(input().strip())
    if 'J' in temp :
      idx = temp.index('J')
      q_J.append([i,idx,0])
    if 'F' in temp :
      for j in range(len(temp)):
        if temp[j] == 'F' :
          q_F.append([i,j])
    maze.append(temp)

  
  while True: 
    # for i in range(x):
    #   print(maze[i])
    # print()
    new_J = collections.deque()  
    while q_J:  
      xyz = q_J.popleft()
      x_J = xyz[0]
      y_J = xyz[1]
      minute = xyz[2]
      if maze[x_J][y_J] != 'J': #불이 이동했을 때 불에 잡힘
        continue
      if x_J == 0 or x_J ==  x - 1 or y_J == 0 or y_J == y - 1:
        print(minute + 1)
        return
      for i in range(4):
        xx = x_J + move[i][0]
        yy = y_J + move[i][1]
        if 0 <= xx < x and 0 <= yy < y and check[xx][yy] == 0 and maze[xx][yy] == '.' :
          check[xx][yy] = 1
          maze[xx][yy] ='J'
          new_J.append([xx,yy,minute+1])
    if len(new_J) == 0:
      print("IMPOSSIBLE")
      return 
    q_J = new_J  
    new_F = collections.deque()      
    while q_F: #현재 있는 불 모두 이동
      xy = q_F.popleft()
      x_F = xy[0]
      y_F = xy[1]
      for i in range(4):
        xx = x_F + move[i][0]
        yy = y_F + move[i][1]
        if 0 <= xx < x and 0 <= yy < y and (maze[xx][yy] == 'J' or maze[xx][yy] == '.'): 
          maze[xx][yy] = 'F'
          new_F.append([xx,yy])
    q_F = new_F    

bfs()
