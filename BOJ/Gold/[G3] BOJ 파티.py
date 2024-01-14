import sys
import heapq
input=sys.stdin.readline

n,m,x = map(int, input().split())
city = [[] for i in range(n+1)]
dis = [sys.maxsize for _ in range(n + 1)]

for _ in range(m):
    a,b,c = map(int,input().split())
    city[a].append((b,c)) 

def check_dis(start) :
    pq = []
    heapq.heappush(pq, (0,start))
    dis[start] = 0
    while pq :
        current_dis, now = heapq.heappop(pq)
        for road in city[now]:
            if dis[road[0]] > road[1] + current_dis : #다른 곳 거치는것이 한번에 가는것보다 빠를때
                dis[road[0]] = road[1] + current_dis
                heapq.heappush(pq, (dis[road[0]], road[0]))

res = [0 for _ in range(n + 1)]
check_dis(x)
for i in range(1,n+1): res[i] = dis[i]

for i in range(1, n + 1):
    if i == x : continue
    dis = [sys.maxsize for _ in range(n + 1)]
    check_dis(i)
    res[i] += dis[x]

print(max(res))
