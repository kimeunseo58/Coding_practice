#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n, m;
int main() { 
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> n >> m;
    map<string,int> pokemonName;
	map<int, string> pokemonNumber;
    string temp; 
    for(int i = 1; i<= n; i++){
        cin >> temp;
		pokemonName.insert({temp,i});
		pokemonNumber.insert({i,temp});
    }
    for(int i =1; i <= m;i++){
        cin >> temp;
        if(temp[0] >= '0' && temp[0] <= '9'){
            int j = stoi(temp);
            cout << pokemonNumber[j];
        }
        else cout << pokemonName[temp];
        cout << '\n';
    }  
}
