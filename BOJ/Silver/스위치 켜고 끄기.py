import sys
input=sys.stdin.readline
n = int(input())
switch = list(map(int, input().split()))
m = int(input())

for i in range(m):
  gender,number = map(int, input().split())
  idx = number - 1
  if gender == 1 :
    while idx < len(switch)   :
      if switch[idx] == 0 :
        switch[idx] = 1
      else :
        switch[idx] = 0
      idx += number
  else:
    cnt = 0
    if switch[idx] == 0 :
        switch[idx] = 1
    else :
      switch[idx] = 0
    while idx - cnt >= 0 and idx + cnt < len(switch) :
      if switch[idx + cnt] == switch[idx - cnt]:
        if switch[idx + cnt] == 0 :
          switch[idx + cnt] = 1
        else :
          switch[idx + cnt] = 0
        if switch[idx - cnt] == 0 :
          switch[idx - cnt] = 1
        else :
          switch[idx - cnt] = 0
        cnt += 1
      else:
        break
  

for i in range(1, n+1):
  print(switch[i - 1], end=' ')
  if i % 20 == 0:
    print()

