#include<iostream>
#include<vector>
using namespace std;

void print(int n, vector<int>v, int cur) {
	for (int i = 0; i < cur; i++)cout << v[i] << " ";
	cout << endl;
	int s = cur ? v[cur - 1] + 1 : 0;
	for (int i = s; i < n; i++) {
		v[cur] = i;
		print(n, v,cur + 1);
	}
}

int main() {
	vector<int>v;
	for (int i = 0; i < 4; i++)
		v.push_back(i);
	print(4, v, 0);
	return 0;
}