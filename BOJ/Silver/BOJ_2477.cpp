#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct melon{
    int d;
    int len;
};
int main() {    
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    melon a[6]; //전체
    melon b[12];
    int check[5] = {0,};
    int temp =0;
    for(int i=0;i<6;i++) {
        cin >> a[i].d >> a[i].len;
        b[i] = a[i];
        b[i+6] = a[i];
    }
    for(int i=2;i<12;i++){
        if(b[i-2].d == b[i].d && b[i-1].d == b[i+1].d){
            temp =  b[i].len *b[i-1].len;
            check[b[i-2].d] = 1;
            check[b[i-1].d] = 1;
            break;
        }
    }
    int big = 1;
    for(int i=1; i<=4;i++){
        if(check[i] == 0){
            for(int j =0;j<6;j++){
                if(a[j].d == i) {
                    big *= a[j].len;
                    break;
                }
            }
        } 
    }
    cout << (big - temp) * n;
 	return 0;
}
