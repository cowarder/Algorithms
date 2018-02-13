#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main() {
	vector<int>ying;
	vector<int>wan;
	for (int i = 2; i <= 60; i++) {
		vector<int>v;
		for (int j = 1; j < i; j++) {
			if (i%j == 0)
				v.push_back(j);
		}
		if (accumulate(v.begin(), v.end(), 0) == i)
			wan.push_back(i);
		else if (accumulate(v.begin(), v.end(), 0) > i)
			ying.push_back(i);
	}
	cout << "E:";
	for (int i = 0; i < wan.size(); i++)
		cout << " " << wan[i];
	cout << endl;
	cout << "G:";
	for (int i = 0; i < ying.size(); i++)
		cout << " " << ying[i];
	cout << endl;
	return 0;
}