#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Mouse {
public:
	int weight;
	string color;
	bool operator<(const Mouse& m)const {
		return weight > m.weight;
	}
};

vector<Mouse>v;

int main() {
	int n;
	while (cin >> n) {
		v.clear();
		v.resize(0);
		v.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].weight >> v[i].color;
		sort(v.begin(), v.end());
		for (int i = 0; i < n; i++)
			cout << v[i].color << endl;
	}
	return 0;
}