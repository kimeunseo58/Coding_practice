import sys
input=sys.stdin.readline

def is_full(s, board):
  num_x = 0
  num_o = 0
  flag = True
  for i in range(len(s)):
    if s[i] == 'X' :
      num_x += 1
    elif s[i] == 'O' :
      num_o += 1
    else :
      flag = False

  winner = check_winner(board)
  if flag == True :
    if num_x - 1 != num_o:
      return "invalid"
    else :
      if winner == 'X' :
        return "valid"
      elif winner == "no_winner":
        return "valid"
      else :
        return "invalid"
  else :
    if winner == "no_winner":
      return "invalid"
    elif winner == 'O':
      if num_x == num_o:
        return "valid"
      else:
        return "invalid"
    elif winner == 'X' :
      if num_x - 1 == num_o:
        return "valid"
      else:
        return "invalid"
    else : 
      return winner

def check_winner(board):
  win = {'X' : 0, 'O' : 0}
  #가로 3줄 검사
  for i in board :
    if i[0] == i[1] == i[2] == 'X' :
      win['X'] += 1
    elif i[0] == i[1] == i[2] == 'O' :
      win['O'] += 1

  #세로 3줄 검사
  for i in range(3) :
    if board[0][i] == board[1][i] == board[2][i] == 'X' :
      win['X'] += 1    
    elif board[0][i] == board[1][i] == board[2][i] == 'O' :
      win['O'] += 1

  #대각선 2개 검사
  if board[0][0] == board[1][1] == board[2][2] == 'X' :
      win['X'] += 1    
  elif board[0][0] == board[1][1] == board[2][2] == 'O' :
      win['O'] += 1
  
  if board[0][2] == board[1][1] == board[2][0] == 'X' :    
      win['X'] += 1    
  elif board[0][2] == board[1][1] == board[2][0] == 'O' :
      win['O'] += 1
  
  if win['X'] >= 3 or win['O'] >= 3  :
    return "invalid"
  if win['X'] >= 1 and win['O'] >= 1 :
    return "invalid"
  if 2 >= win['X'] >= 1 and win['O'] == 0:
    return 'X'
  if 2 >= win['O'] >= 1 and win['X'] == 0:
    return 'O'
  if win['O'] + win['X'] == 0:
    return "no_winner"


while True:
  s = str(input().strip())
  if s == "end":
    break
  board = [[s[0:3][0],s[0:3][1],s[0:3][2]],
           [s[3:6][0],s[3:6][1],s[3:6][2]],
           [s[6:9][0],s[6:9][1],s[6:9][2]]]
  
  res = is_full(s,board)
  print(res)
