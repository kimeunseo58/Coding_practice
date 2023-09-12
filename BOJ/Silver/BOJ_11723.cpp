#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n, m;
vector<int> v;
int finding(int n){
    for(int i =0;i<v.size(); i++){
        if(v[i] == n) return i;
    }
    return -1;
}
void whatQuestion(string s){
    if(s == "add"){
        cin >> n;
        if(finding(n) == -1)  v.push_back(n);
        else return;
    }
    else if(s == "remove"){
        cin >> n;
        if(finding(n) == -1) return;
        else v.erase(remove(v.begin(), v.end(), n), v.end());
    }
    else if(s == "check"){
        cin >> n;
        if(finding(n) == -1)cout << 0 <<'\n';
        else cout << 1 << '\n';
    }
    else if(s == "toggle"){
        cin >> n;
        if(finding(n) == -1) v.push_back(n);
        else v.erase(remove(v.begin(), v.end(), n), v.end());
    }
    else if(s == "all"){
        v.clear();
        for(int i =1; i<=20; i++) v.push_back(i);
    }
    else if(s == "empty"){
        v.clear();
    }
}
int main() { 
    ios::sync_with_stdio(false);
	cin.tie(0);

    cin >> m;
    string q;
    for(int i=0;i<m;i++){
        cin >> q;
        whatQuestion(q);
    }
}
