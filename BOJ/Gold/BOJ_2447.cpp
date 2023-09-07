#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n;
char star[6561][6561];
void putSpace(int x,int y, int k){
    int p = k / 3;
    for(int i= x + p;i < x + p * 2;i++){
        for(int j = y + p;j < y + p * 2;j++)star[i][j] = ' ';
    }
    if (k != 3){
        putSpace(x,y,p);
        putSpace(x,y + p,p);
        putSpace(x,y + 2 * p,p);
        putSpace(x + p,y,p);
        putSpace(x + 2 * p,y,p);
        putSpace(x + p,y + 2 * p,p);
        putSpace(x + 2 * p,y + p,p);
        putSpace(x + 2 * p,y + 2 * p,p);
    }
    
    
}
int main()
{
    cin >> n;
    int k = n / 3;
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++) {
            //if((i >=k && j >= k) && (i < (k * 2) && j < (k * 2))) star[i][j] = ' ';
            //else
            star[i][j] = '*';
        }
    }
    putSpace(0,0,n);
    
    
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            cout << star[i][j];
        }
        cout << '\n';
    }

    return 0;
}
