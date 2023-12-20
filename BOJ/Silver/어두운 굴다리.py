import sys
import math
input=sys.stdin.readline
n = int(input())
m = int(input())
x = list(map(int, input().split()))
x.sort()

res = max(x[0], n - x[len(x) - 1])
for i in range(1, len(x)):
  res = max(res, math.ceil((x[i] - x[i-1]) / 2))
print(res)
