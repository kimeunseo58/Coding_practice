#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << "#" << test_case << " ";
        string s;
        cin >> s;
        char flag = s[s.length() -1];
        int res = 0;
        for(int i = s.length()-1 ; i >= 0; i--){
        	if(flag != s[i]){
            	res++;
                flag = s[i];
            }
        }
        if(s[0] == '1') res++;
        cout << res << "\n";


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
