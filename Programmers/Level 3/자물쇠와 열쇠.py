def find_key(key, lock, n, m) :
    #위 -> 아래로 이동
    #오른쪽 이동
    for vertical in range(n):
        for line in range(n):
            i_key = 0
            flag = True
            for i in range(n):
                j_key = 0
                for j in range(n):
                    if n > i >= line and n > j >= vertical and i_key < m and j_key < m :
                        if key[i_key][j_key] + lock[i][j] != 1:
                            flag = False
                            break
                        j_key += 1
                    elif lock[i][j] != 1 :
                        flag = False
                        break
                if flag == False: break #해당 위치의 해당 키는 불가
                if n > i >= line and n > j >= vertical: i_key += 1
            if flag == True : return True # 키가 맞음
                       
    #왼쪽 이동
    for vertical in range(n):
        for line in range(n):
            i_key = 0
            flag = True
            for i in range(n):
                j_key = vertical
                for j in range(n):
                    if n > i >= line and n > j >= 0 and i_key < m and j_key < m :
                        if key[i_key][j_key] + lock[i][j] != 1:
                            flag = False
                            break
                        j_key += 1
                    elif lock[i][j] != 1 :
                        flag = False
                        break
                if flag == False: break #해당 위치의 해당 키는 불가
                if n > i >= line and n > j >= 0: i_key += 1
            if flag == True : return True # 키가 맞음
        #위로 이동
            #오른쪽 이동
    for vertical in range(n):
        for line in range(n):
            i_key = line
            flag = True
            for i in range(n):
                j_key = 0
                for j in range(n):
                    if n > i >= 0 and n > j >= vertical and i_key < m and j_key < m :
                        if key[i_key][j_key] + lock[i][j] != 1:
                            flag = False
                            break
                        j_key += 1
                    elif lock[i][j] != 1 :
                        flag = False
                        break
                if flag == False: break #해당 위치의 해당 키는 불가
                if n > i >= 0 and n > j >= vertical: i_key += 1
            if flag == True : return True # 키가 맞음
                       
    #왼쪽 이동
    for vertical in range(n):
        for line in range(n):
            i_key = line
            flag = True
            for i in range(n):
                j_key = vertical
                for j in range(n):
                    if n > i >= 0 and n > j >= 0 and i_key < m and j_key < m :
                        if key[i_key][j_key] + lock[i][j] != 1:
                            flag = False
                            break
                        j_key += 1
                    elif lock[i][j] != 1 :
                        flag = False
                        break
                if flag == False: break #해당 위치의 해당 키는 불가
                if n > i >= 0 and n > j >= 0: i_key += 1
            if flag == True : return True # 키가 맞음
    return False
def solution(key, lock):
    m = len(key)
    n = len(lock)
    key_90 = [[0 for _ in range(m)] for _ in range(m)]
    key_180 = [[0 for _ in range(m)] for _ in range(m)]
    key_270 = [[0 for _ in range(m)] for _ in range(m)]
    for i in range(m):
        for j in range(m-1,-1,-1):
            key_90[i][m - 1 - j] = key[j][i]
            key_180[m - 1 - i][m - 1 - j] = key[i][j]
            key_270[m - 1 - j][i] = key[i][j]
    print(find_key(key,lock, n, m))
    if find_key(key,lock, n, m) == False:
        if find_key(key_90, lock, n, m) == False :
            if find_key(key_180, lock, n, m) == False :
                if find_key(key_270, lock, n, m) == False : return False
                else : return True
            else : return True
        else : return True
    else : return True
