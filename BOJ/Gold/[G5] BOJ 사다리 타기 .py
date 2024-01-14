import sys
import copy
input = sys.stdin.readline
k = int(input())
n = int(input())
goal = list(input().strip())


people = [chr(i) for i in range(65, 65 + k)]
temp =['a' for _ in range(k)]
cnt = 0
def ladder_change(ld, af,bf):
    i = 0
    while i < k - 1:
        if ld[i] == '*':
            af[i] = bf[i]
        else :
            af[i + 1] = bf[i]
            af[i] = bf[i + 1]
            i += 1
        i += 1
    if ld[-1] == '*' : af[-1] = bf[-1]
    return af

while cnt < n:
    ladder = list(input(). strip())
    if ladder[0] == '?' : break
    people = copy.deepcopy(ladder_change(ladder, temp, people))
    #print(people)
    cnt += 1

ladder = [list(input().strip()) for _ in range(n - cnt - 1)]
for i in range(len(ladder) -1, -1, -1):
    goal = copy.deepcopy(ladder_change(ladder[i], temp, goal))

answer = ""
i = 0
while i < len(goal) - 1 :
    if goal[i] == people[i + 1] and goal[i + 1] == people[i] : answer += '-'
    else: answer += '*'
    i += 1
if ladder_change(answer, temp, people) != goal: print('x' * (k - 1))
else : print(answer)
