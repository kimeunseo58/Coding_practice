#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int n;
	cin >> n;
	int test[100000] = {0,};
	int testAll[100000] = {0,};

	int score[1001] = {0,};
	int scoreAll[3001] = {0,};

	int rank = 1;
	for(int i=0;i<3;i++){
		int score[1002] = {0,};
		for(int j =0; j<n; j++){
			cin >> test[j];
			testAll[j] += test[j];
			score[test[j]]++;
			if(i == 2) scoreAll[testAll[j]]++;
		}
		for(int j =0; j<n; j++){
			for(int k = test[j] + 1; k <= 1000; k++)
				rank += score[k];
			cout << rank <<" ";
			rank = 1;
		}
		cout << '\n';

		for(int j = 0; j<=1000; j++) score[i] = 0;
	}
	for(int i=0;i<n;i++){
		for(int j = testAll[i] + 1; j <= 3000; j++)
			rank += scoreAll[j];
		cout << rank << " ";
		rank = 1;
	}

	return 0;
}
