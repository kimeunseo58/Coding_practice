#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct guitar{
    int six;
    int one;
};
bool compare1 (guitar &a, guitar&b){
    if(a.six == b.six) return a.one < b.one;
    else return a.six < b.six;
}
bool compare2 (guitar &a, guitar&b){
    if(a.one == b.one) return a.six < b.six;
    else return a.one < b.one;
}
int main() {    
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    guitar arr[101];
    for(int i=0;i<m;i++) cin >> arr[i].six >> arr[i].one;
    int numOfOne = n % 6;
    int numOfSix = n / 6;
    
    sort(arr,arr + m, compare1); //6개 묶음 순으로 정렬
    int minSix =  arr[0].six;
    sort(arr, arr + m,compare2); //한개 순으로 정렬
    int minOne =  arr[0].one;
    
    int a = minSix * numOfSix + minOne * numOfOne; //6개 묶음과 낱개로 개수 맞춰서 사기
    int b = (numOfSix + 1) * minSix; //6개 묶음으로 사기, 낱개도 묶음으로 처리하기 위해 + 1
    int c = minOne * n; //낱개 모두 각각 사기

    int res = min({a,b,c});
    cout << res;
 	return 0;
}
