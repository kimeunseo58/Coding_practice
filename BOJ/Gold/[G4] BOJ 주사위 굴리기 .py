import sys
input=sys.stdin.readline

n,m,x,y,k = map(int, input().split())
maps = [list(map(int, input().split())) for _ in range(n)]
move =[[0,1],[0,-1],[-1,0],[1,0]]
dice =[
  [0,0,0,0],
  [0,0,0,0],
  [0,0,0,0],
  [0,0,0,0],
] #위 : 1,1  아래 : 1,3
order_list = list(map(int,input().split()))
for order_cnt in range(k):
  order = order_list[order_cnt] - 1
  # 0 : 동 , [x][y+1]  # 1 : 서 , [x][y-1]  # 2 : 북 , [x-1][y]  # 3 : 남 , [x+1][y]
  xx = x + move[order][0]
  yy = y + move[order][1]
  if xx < 0 or xx > n - 1 or yy < 0 or yy > m - 1 : continue
  x = xx
  y = yy


  if order == 0 :
    temp = dice[1][0]
    for i in range(0,3):
      dice[1][i] = dice[1][i + 1]
    dice[1][3] = temp
    dice[3][1] = dice[1][3]
  elif order == 1 : 
    temp = dice[1][3]
    for i in range(3,0,-1):
      dice[1][i] = dice[1][i-1]
    dice[1][0] = temp
    dice[3][1] = dice[1][3]
  elif order == 2:
    temp = dice[3][1]
    for i in range(3,0,-1):
      dice[i][1] = dice[i-1][1]
    dice[0][1] = temp
    dice[1][3] = dice[3][1]
  elif order == 3: 
    temp = dice[0][1]
    for i in range(0,3):
      dice[i][1] = dice[i + 1][1]
    dice[3][1] = temp
    dice[1][3] = dice[3][1]

  if maps[xx][yy] == 0: maps[xx][yy] = dice[1][3]
  else : 
    dice[1][3] = maps[xx][yy]
    dice[3][1] = maps[xx][yy]
    maps[xx][yy] = 0
  
  #print(dice)
 # print(maps)
  print(dice[1][1])
