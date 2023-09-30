#include<iostream>

using namespace std;
int n,k;
int map[16][16];
int res;
void check(){
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
        	int num = 0 ;
            if( (i == 0 && map[i][j] == 1) || (i != 0 && map[i - 1][j] == 0 && map[i][j] == 1)){
                int x = i;
                num = 0;
            	while(map[x][j] == 1 && x < n) {
                    num++; 
                    x++;
                }
                if(num == k)  res++;
            }
            if( (j == 0 && map[i][j] == 1) ||  (j != 0 && map [i][j -1] == 0  && map[i][j] == 1) ){
                int y = j;
                num = 0;
                while(map[i][y] == 1 && y < n) {     
                    num++; 
                    y++;
                } 
                if(num == k)  res++;
            }			
        }
    }  
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        cout << "#" << test_case << " ";
        cin >> n>> k;
        for(int i=0;i<n;i++){
            for(int j =0; j<n;j++) cin >> map[i][j];
        }
        res =0;
        check();
        cout << res << '\n';
	}
	return 0;
}
