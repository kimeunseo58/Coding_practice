import sys
import collections
input=sys.stdin.readline

maps = [list(input().strip()) for _ in range(12)]
q = collections.deque()
res = 0
move = [[0,-1],[0,1],[1,0],[-1,0]]

while True:
  res_flag = False
  check = [[0,0,0,0,0,0] for _ in range(12)]
  for i in range(12):
    for j in range(6):
      if maps[i][j] == '.' or check[i][j] == 1: continue
      q.append([i,j,maps[i][j]])
      check[i][j] = 1
      same_color = [[i,j]]
      same_flag = False
      while q:
        xy = q.popleft()
        for mv in move:
          x = xy[0] + mv[0]
          y = xy[1] + mv[1]
          if 0 <= x < 12 and 0 <= y < 6 and check[x][y] == 0 and maps[x][y] == xy[2]:
            q.append([x,y,xy[2]])
            check[x][y] = 1
            if same_flag == False : same_color.append([x,y])
            else : maps[x][y] = '.'
        if same_flag == False and len(same_color) >=4 :
          for sc in same_color: maps[sc[0]][sc[1]] = '.'
          same_flag = True
          res_flag = True

  if res_flag == False : break

  res += 1
  for j in range(6):
    top = 11
    while top != 0 and maps[top][j] != '.' : top -= 1
    while top > 0:
      i = top
      while i != 0 and maps[i][j] == '.': i -= 1
      if maps[i][j] != '.' :
        maps[top][j] = maps[i][j]
        maps[i][j] = '.'
        top -= 1
      if i == 0 : break
  

print(res)
