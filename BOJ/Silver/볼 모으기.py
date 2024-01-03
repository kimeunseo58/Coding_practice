import sys
input=sys.stdin.readline

n = int(input())
ball = input().strip()

res1 = 0
res2=0
res3=0
res4 = 0

for i in range(n): #빨간색 왼쪽 끝으로 옮기기
  if ball[i] == 'R': res1 += 1
for i in range(n -1, -1, -1):
  if ball[i] == 'R': res1 -= 1
  if ball[i] == 'B': break

for i in range(n): #파란색 왼쪽 끝으로 옮기기
  if ball[i] == 'B': res2 += 1
for i in range(n -1, -1, -1):
  if ball[i] == 'B': res2 -= 1
  if ball[i] == 'R': break


for i in range(n-1, -1, -1): #빨간색 오른쪽 끝으로 옮기기
  if ball[i] == 'R': res3 += 1
for i in range(n):
  if ball[i] == 'R': res3 -= 1
  if ball[i] == 'B': break

for i in range(n-1, -1, -1): #파란색 오른쪽 끝으로 옮기기
  if ball[i] == 'B': res4 += 1
for i in range(n):
  if ball[i] == 'B': res4 -= 1
  if ball[i] == 'R': break

print(min(res1,res2,res3,res4))
