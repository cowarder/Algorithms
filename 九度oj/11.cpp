#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	map<int, vector<int>> hash;
	int m;
	int n;
	int num;
	vector<int> result;
	bool enough = false;
	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) {
			cin >> num;
			hash[num].push_back(num);
		}

		for (auto& x : hash) {
			sort(hash[x.first].begin(), hash[x.first].end());
			for (int i : hash[x.first]) {
				if (result.size() == m) {
					enough = true;
					break;
				}
				result.push_back(i);
			}
			if (enough == true)
				break;
		}
		sort(result.begin(), result.end());
		for (int x : result)
			cout << x << " ";
		cout << endl;
		enough = false;
		result.clear();
		hash.clear();
	}
	return 0;

}