import sys
input=sys.stdin.readline

t = int(input())

while t != 0 :
  n = int(input())
  team = list(map(int, input().split()))
  
  team_dict = {}
  # 0 -> 총점, 1 -> 사람수, 2 -> 5번째 선수의 점수
  
  for i in range(len(team)) :
    if team[i] in team_dict :
      team_dict[team[i]][1] += 1
    else :
      team_dict[team[i]] = [0, 1, 0, 0]
 
  score = 1
  for i in range(len(team)) :
    #print(score, team_dict)
    if team_dict[team[i]][1] == 6:
      if team_dict[team[i]][3] < 4 :
        team_dict[team[i]][0] += score
      team_dict[team[i]][3] += 1
      if team_dict[team[i]][3] == 5 :
        team_dict[team[i]][2] = score
      score += 1
 
  key_remove =[]
  for key, value in team_dict.items() :
    if value[1] != 6 :
      key_remove.append(key)
  for key in key_remove:
    del team_dict[key]    

  sorted_dict = sorted(team_dict, key=lambda k:(team_dict[k][0], team_dict[k][2]))

  print(sorted_dict[0])
  t -= 1
