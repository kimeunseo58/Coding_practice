
#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	for(test_case = 1; test_case <= 10; ++test_case){
		cout << "#" << test_case << " ";
        int dump;
        int arr[100];
        cin >> dump;
        for(int i =0; i<100; i++) cin >> arr[i];
        while(dump--){
            sort(arr , arr+100);
            if(arr[99] - arr[0] <= 1) break;
            arr[0] += 1;
            arr[99] -= 1;
        }
        sort(arr , arr+100);
        cout << arr[99] - arr[0] << '\n';
	}
	return 0;
}
