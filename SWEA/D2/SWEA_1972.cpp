#include<iostream>

using namespace std;
int map[10][10];
int checkC(int a){
	int checkArr[9] ={0,};
    for(int i =0; i<9; i++)
        checkArr[map[a][i] - 1]++;
    for(int i =0; i<9; i++){
    	if(checkArr[i] != 1) return 1;
    }
    return 0;
}

int checkR(int a){
	int checkArr[9] ={0,};
    for(int i =0; i<9; i++)
        checkArr[map[i][a] - 1]++;
    for(int i =0; i<9; i++){
    	if(checkArr[i] != 1) return 1;
    }
    return 0;
}

int check(int a, int b){
	int checkArr[9] ={0,};
    for(int i =a; i<=a + 2; i++){
    	for(int j = b; j <= b + 2; j++)
        	checkArr[map[i][j] - 1]++;
    }
    for(int i =0; i<9; i++){
    	if(checkArr[i] != 1) return 1;
    }
    return 0;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << "#" << test_case << " ";
		for(int i=0;i<9;i++){
            for(int j =0;j<9;j++) cin >> map[i][j];
        }
        int res = 1; 
        for(int i =0; i<9; i++){
        	for(int j =0; j<9;j++){
            	if(i == 0) {
                    res += checkR(j);
                }
                if(j == 0){
                    res += checkC(i);
                }
                if(i %3 == 0 && j % 3== 0) {
                    res +=check(i,j);
                }
            }
        }
        if (res != 1) cout << 0 <<'\n';
        else cout << 1 <<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
