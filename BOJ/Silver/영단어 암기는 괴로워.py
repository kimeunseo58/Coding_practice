import sys
input=sys.stdin.readline

n , m= map(int, input().split())

dict = {}
for idx in range(n):
  word = input().strip()
  if len(word) < m :
    continue
  if word not in dict :
    dict[word] = [word, 1]
  else:
    dict[word][1] += 1

sorted_dict = sorted(dict, key=lambda x:(-dict[x][1], -len(dict[x][0]), dict[x][0]))
for i in sorted_dict:
  print(i)
