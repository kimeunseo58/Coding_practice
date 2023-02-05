#include<iostream>
#include<algorithm>
using namespace std;
struct counsel {
	int time = 0;
	int money = 0;
};
int main() {
	counsel arr[16];
	int dp[16] = {0,};
	int n;
	int finalCounselT = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i].time >> arr[i].money;
	for (int i = n; i > 0; i--) {
		if (arr[i].time + i - 1 <= n) {
			finalCounselT = i;
			dp[finalCounselT] = arr[i].money;
			break;
		}
	}
	for (int i = finalCounselT; i > 0; i--) {
		if (arr[i].time + i - 1 > n) dp[i - 1] = dp[i]; //상담이 불가하므로, 해당 날짜는 상담을 하지 않는다.
		else dp[i -1] = max(dp[i], dp[(i-1) + arr[i-1].time] + arr[i-1].money);
	}
	cout << dp[0];
}