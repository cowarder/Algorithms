#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	while (cin >> N) {
		vector<int>v;
		v.push_back(1);
		int flag;
		for (int i = 1; i <= N; i++) {
			flag = 0;
			for (int j = 0; j < v.size(); j++) {
				int num = i*v[j];
				if ((num + flag) <= 9) {
					v[j] = num+flag;
					flag = 0;
				}
				else {
					v[j] = (num + flag) % 10;
					flag = (num+flag)/10;
				}
			}
			while (flag) {
				v.push_back(flag % 10);
				flag /= 10;
			}
		}
		for (int i = v.size() - 1; i >= 0; i--)
			cout << v[i];
		cout << endl;
	}
	return 0;
}