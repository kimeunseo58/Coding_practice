import sys
import heapq
input=sys.stdin.readline

n,k = map(int, input().split())
maps = [list(map(int,input().split())) for _ in range(n)]
s,x,y = map(int, input().split())
move = [[0,1],[0,-1],[1,0],[-1,0]]

pq = []
for i in range(n):
  for j in range(n):
    if maps[i][j] != 0:
      heapq.heappush(pq,(maps[i][j], i, j))

for sec in range(s):
  temp_list=[]
  while len(pq) != 0:
    temp_tuple = heapq.heappop(pq)
    for mv in move:
      virus = temp_tuple[0]
      xx = temp_tuple[1] + mv[0]
      yy = temp_tuple[2] + mv[1]
      if 0 <= xx < n and 0 <= yy < n and maps[xx][yy] == 0 :
        maps[xx][yy] = virus
        heapq.heappush(temp_list, (virus,xx,yy))
  pq = temp_list

print(maps[x-1][y-1])
