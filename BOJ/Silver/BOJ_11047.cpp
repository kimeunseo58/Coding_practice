#include <iostream>
#include <algorithm>

using namespace std;

int arr[11];
int main() {
    int n,k;
    cin >> n >> k;
    int idx = 0;
    int answer = 0;
    for(int i =0;i<n;i++) cin >> arr[i];
    for(int i =0;i<n;i++){
        if(arr[i] >= k) {
            idx = i;
            break;
        }
        idx = i;
    }
    for(int i = idx;i >= 0;i--){
        while(k - arr[i] >= 0){
            k -= arr[i];
            answer++;
        }
    }
    cout << answer;
}
