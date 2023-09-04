#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string s;
    int result = 0;
    int arr[10] = {0,};
    cin >> s;
    for(int i=0;i<s.length();i++)
    {
        int a = s[i] - '0';
        arr[a]++;
    }
    int k = (arr[6] + arr[9]) / 2;
    if((arr[6] + arr[9]) % 2 == 1) k += 1;
    arr[6] = k;
    for(int i=0;i<9;i++){
        if(arr[i] > result) result = arr[i];
    }
    cout << result;
}
