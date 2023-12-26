import sys
input=sys.stdin.readline

n = int(input().strip())
num = list(map(int, input().strip().split()))
num.sort()

res = 0
for idx in range(n):
  left = 0
  right = n - 1
  num_of_same = 0
  for j in range(idx + 1, n):
    if num[j] != num[idx] :
      break
    num_of_same += 1
  right += num_of_same
  if right > n -1 :
    right = n -1
  #print(idx, left,right,num[idx])
  while left < right :
    if left == idx:
      left += 1
      continue
    if right == idx :
      right -= 1
      continue
    if num[left] + num[right] == num[idx]:
      res += 1
      break
    if num[left] + num[right] < num[idx]:
      left += 1
    elif num[left] + num[right] > num[idx]:
      right -= 1
print(res)
