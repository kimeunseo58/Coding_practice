import sys
import copy
import collections
input=sys.stdin.readline

n,m = map(int, input().split())
arr = [list(map(int,input().split())) for _ in range(n)]
res = -1

q = collections.deque()
for i in range(n):
  for j in range(m):
    if arr[i][j] == 2:
      q.append([i,j])

move =[[0,1],[0,-1],[1,0],[-1,0]]
def bfs(a):
  global res
  room = copy.deepcopy(a)
  my_q = q.copy()
  while my_q:
    xy = my_q.pop()
    x = xy[0]
    y = xy[1]
    for dir in move:
      xx = x + dir[0]
      yy = y + dir[1]
      if 0 <= xx < n and 0 <= yy < m and room[xx][yy] == 0:
        room[xx][yy] = 2
        my_q.append([xx,yy])
  temp_res = 0
  for i in range(n):
    for j in range(m):
      if room[i][j] == 0: temp_res += 1
  res = max(res, temp_res)
def wall():
  for i in range(n):
    for j in range(m):
      if arr[i][j] == 0:
        arr[i][j] = 1
        for a in range(n):
          for b in range(m):
            if arr[a][b] == 0:
              arr[a][b] = 1
              for x in range(n):
                for y in range(m):
                  if arr[x][y] == 0:
                    arr[x][y] = 1
                    bfs(arr)
                    arr[x][y] = 0
              arr[a][b] = 0
        arr[i][j] = 0
    
wall()
print(res)
