#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int check(string ss){
    stack<char> s;
    for(int i =0; i<ss.length(); i++){
        char c = ss[i];
        if(c == '{' || c == '[' || c == '(') s.push(c);
        if(c == '}'){
            if(s.empty()) return -1;
            if(s.top() == '{') s.pop();
            else return -1;
        }
        else if(c == ']'){
            if(s.empty()) return -1;
            if(s.top() == '[') s.pop();
            else return -1;
        }
        else if(c == ')'){
            if(s.empty()) return -1;
            if(s.top() == '(') s.pop();
            else return -1;
        }   
    }
    if(!s.empty()) return -1;
    
    return 1;
}

int solution(string s) {
    int answer = 0;
    for(int i = 0; i< s.length(); i++){
        string temp = s.substr(i, s.length()) + s.substr(0, i);
       if(check(temp) == 1)answer++;
    }
    return answer;
}
