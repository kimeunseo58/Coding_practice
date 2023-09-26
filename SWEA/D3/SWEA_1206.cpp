#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	for(test_case = 1; test_case <= 10; ++test_case){
		cout << "#" << test_case << " ";
        int n;
        int arr[1001] ={0, };
        int res = 0;
        cin >> n;
        for(int i =0; i<n;i++) cin >> arr[i];
        for(int i =2; i< n-2; i++){
            int maxBuilding = max(max(arr[i-2], arr[i-1]), max(arr[i+1], arr[i+2]));
            if( arr[i] > maxBuilding) res += arr[i] - maxBuilding; 
        }
        cout << res <<'\n';
	}
	return 0;
}
