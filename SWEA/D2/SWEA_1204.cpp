
#include<iostream>
#include <algorithm>
using namespace std;
struct grade{
	int num;
    int g;
};
bool compare(grade &a, grade &b){
	if(a.num == b. num) return a.g > b.g;
    return a.num > b.num;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
    
    while(T--){
        cin >> test_case;
        cout << "#" << test_case << " ";
        grade G[101];
        for(int i =0; i< 100; i++) {
            G[i].g = i + 1;
            G[i].num = 0;
        }
        for(int i =0; i<1000; i++){
        	int x;
            cin >> x;
            G[x - 1].num++;
        }
        sort(G,G+100, compare);
        cout << G[0].g << '\n';
    }
	
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
