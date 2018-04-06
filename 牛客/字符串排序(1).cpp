#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

class Node {
public:
	string s;
	bool operator<(const Node& s1) {
		return s.length() < s1.s.length();
	}
};

int main() {
	string n;
	while (getline(cin, n)) {
		stringstream ss(n);
		int n;
		ss >> n;
		string s;
		vector<Node>v;
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			if (s == "stop")
				break;
			Node n;
			n.s = s;
			v.push_back(n);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
			cout << v[i].s << endl;
	}
	return 0;
}