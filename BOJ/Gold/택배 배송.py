import sys, heapq
input=sys.stdin.readline

n,m = map(int,input().split())
node = [[] for _ in range(n + 1)]
dis=[sys.maxsize for _ in range(n + 1)]
for _ in range(m):
    a,b,c = map(int,input().split())
    node[a].append((c,b))
    node[b].append((c,a))


dis[1] = 0
q = []
heapq.heappush(q, (0, 1))

while q :
    cost, pnt = heapq.heappop(q)
    for nd in node[pnt] :
        if dis[nd[1]] > nd[0] + cost :
            dis[nd[1]] = nd[0] + cost
            heapq.heappush(q, (dis[nd[1]], nd[1]))
    
print(dis[n])
