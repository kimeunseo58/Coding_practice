#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct meeting{
	string name;
	int start;
	int end;
};

bool compare(meeting &a, meeting &b){
	if(a.name == b.name){
		if(a.start == b.start) return a.end < b.end;
		else return a.start < b.start;
	}
	else return a.name < b.name;
}

int main(int argc, char** argv)
{
	int n,m;
	string meetingRoom[51];
	meeting meetingArr[101];
	cin >> n >> m;
	for(int i =0; i<n;i++) cin >> meetingRoom[i];
	for(int i =0; i<m;i++) cin >> meetingArr[i].name >> meetingArr[i].start >> meetingArr[i].end;
	sort(meetingArr, meetingArr+m, compare);
	sort(meetingRoom,meetingRoom + n);
	vector<vector<string>> res;		
	int j =0;
	for(int i = 0; i < n; i++){
		int start[9] = {9,10,11,12,13,14,15,16,17};
		int end[9] = {10,11,12,13,14,15,16,17,18};
		while(meetingRoom[i] == meetingArr[j].name){
			for(int k =0;k < 9; k++){
				if(start[k] < meetingArr[j].end && start[k] >= meetingArr[j].start ) start[k] = -1;
				if(end[k] <= meetingArr[j].end && end[k] > meetingArr[j].start ) end[k] = -1;
			}
			j++;	
		}
		for(int h =1; h < 9; h++){
			if(start[h] == end[h-1]){
				start[h] = -1;
				end[h - 1] = -1;
			}
		}		
		vector<int>s;
		vector<int>e;
		for(int h =0; h < 9; h++){
			if(start[h] != -1) s.push_back(start[h]);
			if(end[h] != -1) e.push_back(end[h]);
		}
		cout << "Room " << meetingRoom[i] << ":\n";
		if(s.size() == 0) cout << "Not available\n";
		else cout << s.size() << " available:\n";
		for(int h =0;h<s.size(); h++){
			if(s[h] == 9) cout << "09-" <<e[h] <<'\n';
			else cout <<s[h] << "-" <<e[h] <<'\n';
		}
		if(i != n -1 ) cout << "-----\n";
	}
	return 0;
}
