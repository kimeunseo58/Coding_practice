#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
struct number{
    int x;
    int idx;
};
bool compare(number &a, number &b){
    if(a.x == b.x) {
        return a.idx < b.idx;
    }
    else return a.x < b.x;
}
bool compare2(number &a, number &b){
    if(a.idx == b.idx) return a.x < b.x;
    else return a.idx < b.idx;
}
int main() { 
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> n;
    number arr[1000001];
    vector<int> num;

    for(int i =0;i<n;i++){
        cin >> arr[i].x;
        arr[i].idx =i;
        num.push_back(arr[i].x);
    }
    sort(arr,arr+n,compare);
    sort(num.begin(),num.end());
    arr[0].x = 0;
    for(int i=1;i<n;i++){
        if(num[i-1] == num[i]) arr[i].x = arr[i - 1].x;
        else arr[i].x = arr[i - 1].x + 1;
    }
    sort(arr,arr+n,compare2);
    
    for(int i=0;i<n;i++){
        cout << arr[i].x << " ";
    }
}
