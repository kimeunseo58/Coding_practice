#include<iostream>
using namespace std;
int main() {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int k = 0;
        int j, answer;
        for (int i = 0; i < 10; i++) {
            cin >> j;
            k += j;
        }
        if (k % 10 >= 5)answer = k / 10 + 1;
        else answer = k / 10;
        cout << "#" << test_case << " " << answer << '\n';
    }
    return 0;
}