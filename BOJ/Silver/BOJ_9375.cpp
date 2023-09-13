#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main() { 
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);
    int t,n,answer;
    cin >> t;
    while(t--){
        cin >> n;
        answer = 1;    
        map <string, int> cloth;
        for(int i=0;i<n;i++){
            string key, value;
            cin >> value >> key;
            cloth[key]++;
        }
        for(auto i = cloth.begin(); i != cloth.end() ;i++) answer *= ((i->second) + 1);
        cout << answer - 1 << '\n';
    } 
}
