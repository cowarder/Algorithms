#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

class Node {
public:
	string data;
	string name;
	string year;
	string time;
	string strcost;
	double cost;
	bool operator<(const Node& s) {
		if (cost != s.cost)
			return cost < s.cost;
		else if (year != s.year)
			return year < s.year;
		else
			return time < s.time;
	}
};

int main() {
	string s;
	vector<Node>v;
	while (getline(cin, s) && s.length() != 0) {
		stringstream ss(s);
		Node n;
		n.data = s;
		ss >> n.name >> n.year >> n.time >> n.strcost;
		string cost=n.strcost.substr(0,n.strcost.length()-3);
		stringstream ss1(cost);
		double m;
		ss1 >> m;
		n.cost = m;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i].data<< endl;
	return 0;
}