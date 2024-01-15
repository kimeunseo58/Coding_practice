import sys
input=sys.stdin.readline

n = int(input())
m = int(input())
dis=[[sys.maxsize for _ in range(n + 1)] for _ in range(n + 1)]
for _ in range(m):
    start,end,weight = map(int,input().split())
    dis[start][end] = min(dis[start][end],weight)

for i in range(n + 1):
    dis[i][i] = 0

for i in range(n + 1):
    for j in range(n + 1):
        for k in range(n + 1):
            if dis[j][k] > dis[j][i] + dis[i][k] : 
                dis[j][k] = dis[j][i] + dis[i][k]

for i in range(1, n + 1):
    for j in range(1,n + 1):
        if dis[i][j] == sys.maxsize : print(0, end=" ")
        else : print(dis[i][j], end =" ")
    print()
