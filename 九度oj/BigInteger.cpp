#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int main() {
	string s;
	vector<int>v;
	stack<int> st;
	while (cin >> s) {
		while (!st.empty())
			st.pop();
		v.clear();
		v.resize(0);
		int len = s.length();
		v.resize(len);
		for (int i = 0; i < len; i++)
			v[i] = s[i] - '0';
		for (int i = 0; i < len; i++) {
			if (len == 1 && v[0] == 0) {
				st.push(0);
				break;
			}
			while (v[i] > 0) {
				int c = 0;
				st.push(v[len - 1] % 2);
				for (int j = i; j < len; j++) {
					int tmp = v[j];
					v[j] = (v[j] + c) / 2;
					if (tmp % 2 == 1)
						c = 10;
					else
						c = 0;
				}
			}
		}
		while (!st.empty()) {
			cout << st.top();
			st.pop();
		}
	}
	return 0;
}