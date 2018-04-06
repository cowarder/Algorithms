#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int>v(8);	//表示第i行的列号
vector<string>s;

void search(int cur) {
	if (cur == 8) {
		string m = "";
		for (int i = 0; i < 8; i++)
			m += char(v[i] + '0'+1);
		s.push_back(m);
	} else {
		for (int i = 0; i < 8; i++) {		//遍历可以将当前棋子放在的所有i列，然后判断是否会发生冲突
			bool ok = true;
			v[cur] = i;
			for (int j = 0; j < cur; j++) {
				if (v[j] == v[cur] || v[j] - j == v[cur] - cur || v[j] + j == v[cur] + cur) {
					ok = false;
					break;
				}
			}
			if (ok)search(cur + 1);
		}
	}
}

int main() {
	search(0);
	int n;
	while (cin >> n)
		cout << s[n-1] << endl;
	return 0;
}