import queue
def solution(genres, plays):
    answer = []
    song_all ={}
    song = {}
    for i in range(len(genres)):
        if genres[i] not in song_all:
            song_all[genres[i]] = plays[i]
        else :
            song_all[genres[i]] += plays[i]

        if genres[i] not in song:  
            pq = queue.PriorityQueue()
            pq.put((-plays[i], i))
            song[genres[i]] = pq
        else:
            song[genres[i]].put((-plays[i], i))

    song_all_sorted = sorted(song_all.items(), key=lambda x: -x[1])
    
    for i in range(len(song_all_sorted)):
        temp = song[song_all_sorted[i][0]]
        answer.append(temp.get()[1])
        if not temp.empty(): 
            answer.append(temp.get()[1])

    return answer
