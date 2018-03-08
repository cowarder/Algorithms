#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Pro {
public:
	int begin;
	int end;
	bool operator<(const Pro& b) const {
		return end < b.end;
	}
};

int main() {
	int n;
	while (cin >> n) {
		vector<Pro>v;
		v.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].begin >> v[i].end;
		sort(v.begin(), v.end());
		int num = 0;
		int preTime = -1;
		for (int i = 0; i < n; i++) {
			if (v[i].begin >= preTime) {
				num++;
				preTime = v[i].end;
			}
		}
		cout << num << endl;
	}
	return 0;
}