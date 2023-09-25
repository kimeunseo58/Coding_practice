#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char** argv){
	int T, n;
	cin>>T;
	for(int test_case = 1; test_case <= T; ++test_case){
		cout << "#" << test_case << " ";
        vector<int> v;
        cin >> n;
        for(int i=0;i < n; i++) {
            int a;
            cin >> a;
            v.push_back(a);
        }
        long long money = 0;
        int maxM = v[v.size() - 1];
        for(int i =v.size() - 1; i>= 0; i--){
            if(maxM >= v[i]) money += (maxM - v[i]);
            else maxM = v[i];
        }
        cout << money << '\n';
	}
	return 0;
}
