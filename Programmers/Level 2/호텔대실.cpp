#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int solution(vector<vector<string>> book_time) {
    int room[1441] = {0,};
    int answer = -1;
    for(int i =0; i<book_time.size(); i++){
        int a = book_time[i][0][0] - '0';
        int b = book_time[i][0][1] - '0';
        int c = book_time[i][0][3] - '0';
        int d = book_time[i][0][4] - '0';
        int start = (a * 600) + (b * 60) + (c * 10) + d;
        
        int e = book_time[i][1][0] - '0';
        int f = book_time[i][1][1] - '0';
        int g = book_time[i][1][3] - '0';
        int h = book_time[i][1][4] - '0';
        int end =  (e * 600) + (f * 60) + (g * 10) + h + 10;
        
        for(int j = start; j < end; j++) room[j]++;
    }
    for(int i =0; i < 1440; i++) answer = max(room[i], answer);
    return answer;
}
