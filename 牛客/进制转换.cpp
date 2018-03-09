#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
int main() {
	string s;
	while (cin >> s) {
		vector<int>v;
		int len = s.length();
		v.resize(len);
		for (int i = 0; i < len; i++)
			v[i] = s[i] - '0';
		stack<int>st;
		for (int i = 0; i < len; i++) {
			if (len == 1 && v[0] == 0) {
				st.push(0);
				break;
			}
			while(v[i] > 0) {
				int c = 0;
				st.push(v[len - 1] % 2);
				for (int j = i; j < len; j++) {
					if (v[j] % 2 == 1) {
						v[j] = (v[j] + c) / 2;
						c = 10;
					}
					else {
						v[j] = (v[j] + c) / 2;
						c = 0;
					}
				}
			}
		}
		while (!st.empty()) {
			cout << st.top();
			st.pop();
		}
		cout << endl;
	}
	return 0;
}