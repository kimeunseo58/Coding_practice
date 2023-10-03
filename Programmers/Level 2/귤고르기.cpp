#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
struct fruit{
    int idx;
    int num;
};
bool compare(fruit &a, fruit &b){
    if(a.num == b.num) return a.idx < b.idx;
    return a.num > b.num;
}
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    fruit arr[100001];
    sort(tangerine.begin(), tangerine.end());
    arr[0].idx = tangerine[0];
    arr[0].num = 1;
    int cnt = 1;
    for(int i = 1; i < tangerine.size(); i++){
        if(arr[cnt - 1].idx == tangerine[i]) arr[cnt -1].num++;
        else {
            arr[cnt].idx = tangerine[i];
            arr[cnt].num = 1;
            cnt++;
        }
    }
    sort(arr, arr+cnt, compare);
    int numOfFruit = 0;
    for(int i =0; i< cnt; i++){
        numOfFruit += arr[i].num;
        answer++;
        if(numOfFruit >= k) break;
    }
    return answer;
}
