
#include <iostream>
using namespace std;
int get_num(int i){
    int div = 1;
    int num = i;
    int k  =  i;
    while(i != 0){
        div *= 10;
        i /= 10;
    }
    while(div != 0){
        k += num /div;
        num %= div;
        div /= 10;
    }
    return k;
}

int main(int argc, const char * argv[]) {
    int arr[10001] = {0,};
    for(int i =0; i<10000; i++){
        if(arr[i] != -1)
            arr[i] = i;
        if(get_num(i) < 10000)
            arr[get_num(i)] = -1;
    }
    for(int i =0; i<10000; i++){
        if(arr[i] != -1)
            cout << arr[i] <<'\n';
    }
    return 0;
}
