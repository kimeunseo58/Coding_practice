#include <iostream>
#include <string>
using namespace std;
string moving(string a, string s){
    if(a == "R" && s[0] != 'H') s[0]++;
    else if(a == "L" && s[0] != 'A') s[0]--;
    else if(a == "B" && s[1] != '1')  s[1]--;
    else if(a == "T" && s[1] != '8')  s[1]++;
    else if(a == "RT" && s[0] != 'H' && s[1] != '8'){
        s[0]++;
        s[1]++;
    }
    else if(a == "LT" && s[0] != 'A' && s[1] != '8'){
        s[0]--;
        s[1]++;
    }
    else if(a == "RB" && s[0] != 'H' && s[1] != '1'){
        s[0]++;
        s[1]--;
    }
    else if(a == "LB" && s[0] != 'A' && s[1] != '1'){
        s[0]--;
        s[1]--;
    }
    return s;
}

int main(int argc, const char * argv[]) {
    int n;
    string k,s,c, b_k;
    cin >> k >> s >> n;
    while(n--){
        cin >> c;
        b_k = k;
        k = moving(c,k);
        if(k == s){
            if( s == moving(c,s)){//체스판의 경계면이라서 돌이 움직일 수 없음
                s = k;
                k = b_k;
            }
            else s = moving(c,s);
        }
    }
    cout << k << '\n' << s << '\n';
}
