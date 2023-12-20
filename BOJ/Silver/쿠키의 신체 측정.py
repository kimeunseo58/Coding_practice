import sys
input=sys.stdin.readline
n = int(input())

cookie = [['_' for _ in range(n)] for _ in range(n)]
flag = False
heart =[0,0]
body = []

left = 0
right = 0
left_leg = 0
right_leg = 0
center = 0
for j in range(n):
  s = input()
  for i in range(n) :
    if flag == False and s[i] == '*' :
      heart[0] = j + 2
      heart[1] = i + 1
      flag = True  
    if j == heart[0] - 1 :
      if i < (heart[1] - 1) and s[i] == '*' :
        left += 1
      if i > (heart[1] - 1) and s[i] == '*' :  
        right += 1
    if j >= heart[0] and i == heart[1] - 1 and s[i] == '*' :
      center += 1
    if j >= heart[0] and i == heart[1] - 2 and s[i] == '*' :
      left_leg += 1
    if j >= heart[0] and i == heart[1]  and s[i] == '*' :  
      right_leg += 1


print(heart[0], heart[1])
print(left, right, center, left_leg, right_leg)
