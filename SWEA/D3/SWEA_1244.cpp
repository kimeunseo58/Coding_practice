#include<iostream>
#include<algorithm>
using namespace std;

int res, n;
string s;
void dfs(int a, int cnt){
    if(cnt == n){
        res = max(res, stoi(s));
        return;
    }
    for(int i = a; i < s.length() - 1; i++){
        for(int j = i + 1; j < s.length(); j++){
           	swap(s[i], s[j]);
            dfs(i, cnt + 1);
            swap(s[i], s[j]);
        }
    }
}

int main(){
    int T;
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        cout << "#" << test_case << " ";
        cin >> s >> n;
        if(s.length() == 1) {
            cout << s << '\n';
            return 0;
        }
        if(n <= s.length()){
        	res = 0;
        	dfs(0, 0);
            cout << res << "\n";
        }
        else {
            int temp = n - s.length();
            n = s.length();
            res = 0;
            dfs(0,0); 
            string sT = to_string(res);
            for(int i =0; i<temp; i++) {
                swap(sT[s.length() -1], sT[s.length() -2]);
            }
            cout << sT << '\n';
        }
   	}
    return 0;
}
