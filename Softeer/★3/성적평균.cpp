#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	int n, k;
	cin >> n >> k;
	int arr[1000001];
	for(int i=0;i<n;i++) cin >> arr[i];
	for(int i=0;i<k;i++){
		int a,b;
		double sum = 0;
		cin >> a >> b;
		for(int j = a-1; j < b; j++) sum += arr[j];
		cout << fixed;
		cout.precision(2);
		cout << double(sum / (b - a + 1)) << '\n'; 
	}
	return 0;
}
