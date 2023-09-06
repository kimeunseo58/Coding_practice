#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int L, n, x,y, answer;
    cin >> L;
    vector<int> v(L);

    for (int i = 0; i < L; i++) cin >> v[i];
    v.push_back(0);
    cin >> n;
    bool flag = true;
    sort(v.begin(), v.end());
    
    for (int i = 1; i <= L ; i++) {
        if (n == v[i]) flag = false;
        else if (n < v[i]) {
            x = v[i - 1] + 1;
            y = v[i] - 1;
            break;
        }
    }

    if (flag) answer = (n - x) * (y - n + 1) + (y - n);
    else answer = 0;
    cout << answer;

    return 0;
}
