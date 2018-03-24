#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Node {
public:
	string s;
	int sum;
	bool operator<(const Node& n) {
		return sum < n.sum;
	}
};

int cal(string s) {
	int sum = 0;
	for(int i=0;i<s.length();i++)
		for (int j = i + 1; j < s.length(); j++) {
			if (s[i] > s[j])
				sum++;
		}
	return sum;
}

int main() {
	int k;
	while (cin >> k) {
		vector<Node>v;
		string s;
		for (int i = 0; i < k; i++) {
			cin >> s;
			Node n;
			n.s = s;
			n.sum = cal(s);
			v.push_back(n);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
			cout << v[i].s<<endl;
	}
	return 0;
}