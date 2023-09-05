#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
    int n, m, temp, second;
    vector<int> crane;
    vector<int> box;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        crane.push_back(temp);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        box.push_back(temp);
    }
    sort(crane.begin(), crane.end());
    sort(box.begin(), box.end());
    if (crane.back() < box.back()) {
        cout << -1;
        return 0;
    }
    second = 0;
    while (!box.empty()) {
        second++;
        for (int i = crane.size() - 1; i >= 0; i--) {
            for (int j = box.size() - 1; j >= 0; j--) {
                if (crane[i] >= box[j]) {
                    box.erase(box.begin() + j); //크레인이 들 수 있으면 해당 상자 삭제
                    break; //다음 크레인으로 이동
                }
            }
        }
    }
    cout << second;
    return 0;
}
