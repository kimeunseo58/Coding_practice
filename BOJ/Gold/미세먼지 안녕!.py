import sys
input=sys.stdin.readline

r,c,t = map(int, input().split())
room = [list(map(int,input().split())) for _ in range(r)]
#공기청정기 위치 찾기
cleaner_top = 0
cleaner_bottom = 0
for i in range(r):
  if room[i][0] == -1 :
    cleaner_top = i
    cleaner_bottom = i + 1
    break
  
dir = [[0,1],[0,-1],[1,0],[-1,0]]
def move():
  global room
  new_room = [[0 for _ in range(c)] for _ in range(r)]
  new_room[cleaner_top][0] = -1
  new_room[cleaner_bottom][0] = -1
  # 미세먼지 확장
  for i in range(r):
    for j in range(c):
      if room[i][j] == 0 or room[i][j] == -1: continue
      dust = room[i][j] // 5
      dust_all = room[i][j]
      for d in dir:
        x = i + d[0]
        y = j + d[1]
        if 0 <= x < r and 0 <= y < c and room[x][y] != -1 :
          new_room[x][y] += dust
          dust_all -= dust
      new_room[i][j] += dust_all 
      # for y in new_room:
      #   print(y)
      # print()   
  room = new_room

  # 공기청정기 작동
  # 위쪽 (반시계)
  temp = room[cleaner_top][c-1]
  for i in range(c-1,0,-1):
    room[cleaner_top][i] = room[cleaner_top][i-1]
  room[cleaner_top][1] = 0  
  temp2 = room[0][c-1]
  for i in range(0, cleaner_top):
    room[i][c-1] = room[i+1][c-1]  
  room[cleaner_top - 1][c - 1] = temp
  temp3 = room[0][0]
  for i in range(0,c - 1):
    room[0][i] = room[0][i + 1]
  room[0][c-2] = temp2 
  for i in range(cleaner_top -1, 0, -1):
    room[i][0] = room[i-1][0] 
  room[1][0] = temp3
  
  # 아래쪽 (시계)
  temp = room[cleaner_bottom][c-1]
  for i in range(c-1,0,-1):
    room[cleaner_bottom][i] = room[cleaner_bottom][i-1]
  room[cleaner_bottom][1] = 0  
  temp2 = room[r-1][c-1]
  for i in range(r-1, cleaner_bottom, -1):
    room[i][c-1] = room[i-1][c-1]  
  room[cleaner_bottom + 1][c - 1] = temp
  temp3 = room[r-1][0]
  for i in range(0,c - 1):
    room[r-1][i] = room[r-1][i + 1]
  room[r-1][c-2] = temp2 
  for i in range(cleaner_bottom +1, r-1):
    room[i][0] = room[i+1][0] 
  room[r-2][0] = temp3

for i in range(t):
  move()

res = 0
for i in room:
  res += sum(i)
print(res + 2) #공기청정기 -2 추가 
