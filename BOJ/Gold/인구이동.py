import sys
import collections
input=sys.stdin.readline

n,l,m = map(int, input().strip().split())
country = [[0 for _ in range(n)] for _ in range(n)]

for i in range(n):
  temp = input().strip().split()
  for j in range(n):
    country[i][j] = int(temp[j])
  
move=[[1,0],[-1,0],[0,1],[0,-1]]

def isIn(x,y):
  if 0 <= x < n  and 0 <= y < n :
    return True
  return False 

def bfs(check,start_x,start_y):
  q = collections.deque()
  q.append([start_x,start_y])
  flag = 0
  people = country[start_x][start_y]
  num_of_country = 1
  list_country = [[start_x,start_y]]
  while q:
    xy = q.popleft()
    x = xy[0]
    y = xy[1]
    for i in range(4):
      xx = x + move[i][0]
      yy = y + move[i][1]
      if isIn(xx,yy) and check[xx][yy] == 0 and l <= abs(country[xx][yy] - country[x][y]) <= m:
        check[xx][yy] = 1
        num_of_country += 1
        people += country[xx][yy]
        list_country.append([xx,yy])
        q.append([xx,yy])
    if len(q) == 0 :
      break
  if num_of_country > 1 :       
    people_res = people // num_of_country
    for i in range(len(list_country)):
      country[list_country[i][0]][list_country[i][1]] = people_res
    flag = 1
  return flag


def check_minute():
  minute = 0
  while True :
    flag = 0
    minute += 1
    check = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
      for j in range(n):
        if check[i][j] == 0 :
          check[i][j] = 1
          flag += bfs(check, i, j)
    if flag == 0:
      minute -= 1
      break
  print(minute)

check_minute()
    

