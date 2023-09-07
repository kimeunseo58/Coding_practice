#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct meeting{
    int s;
    int e;
};
bool compare(const meeting& m1, const meeting& m2){
    if(m1.e == m2.e){
        return m1.s < m2.s;
    }
    else return m1.e < m2.e;
}
int main()
{
    int n;
    int end = 0;
    int answer = 1;
    meeting m[100001];
    cin >> n;
    for(int i=0;i<n;i++) cin >> m[i].s >> m[i].e;
    sort(m,m+n,compare);
 
    end = m[0].e;
    for(int i = 1; i<n; i++){
        if(end <= m[i].s){
            end = m[i].e;
            answer++;
        }
    }
    cout << answer;
    return 0;
}
