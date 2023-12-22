#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    int n, x, y;
    cin >> n;
    int res = 0;
    stack<int> s;
    while (n--) {
        cin >> x >> y;
        if ((s.empty() && y != 0) || (!s.empty()&&  s.top() < y)) {
            s.push(y);
            continue;
        }
        while (!s.empty() && s.top() > y ) {
            res++;
            s.pop();
        }
        if ((!s.empty() && s.top() < y) || (s.empty() && y != 0)) s.push(y);
    }

    while (!s.empty()) {
        res++;
        s.pop();
    }
    cout << res;
}
