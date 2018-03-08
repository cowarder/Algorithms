#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	string s;
	int n;
	while (cin >> s >> n) {
		string instr;//指令
		vector<vector<char>>v;
		v.resize(n);
		for (int i = 0; i < n; i++)
			v[i].resize(s.length());
		for (int i = 0; i < n; i++) {
			v[i].assign(s.begin(), s.end());
			cin >> instr;
			char mode = instr[0];
			int low = instr[1]-'0';
			int high = low+int(instr[2]-'0')-1;
			if (mode == '0') {
				while (low < high) {
					swap(v[i][low], v[i][high]);
					low++;
					high--;
				}
			}
			else if (mode == '1') {
				int index = 3;
				for (int j = low; j <= high; j++) {
					//cout << index << " " << instr[index] << endl;
					v[i][j] = instr[index];
					index++;
				}
			}
			s.clear();
			s.assign(v[i].begin(), v[i].end());
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < v[i].size(); j++) {
				cout << v[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}