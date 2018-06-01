#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

map<string, string>zhou;
map<string, string>fa;

int main() {
	string s;
	vector<string>v;
	while (getline(cin, s)) {
		if (s == "@END@")
			break;
		v.push_back(s);
	}
	for (int i = 0; i < v.size(); i++) {
		int index = v[i].find(']');
		string a = v[i].substr(0, index + 1);
		string b = v[i].substr(index + 2, v[i].length() - index);
		zhou[a] = b;
		fa[b] = a.substr(1,a.length()-2);
	}
	int n;
	string sn;
	getline(cin, sn);
	stringstream ss(sn);
	ss >> n;
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		if (s[0] == '[')
			if (zhou.find(s) == zhou.end())
				cout << "what?" << endl;
			else
				cout << zhou[s] << endl;
		else
			if (fa.find(s) == fa.end())
				cout << "what?" << endl;
			else
				cout << fa[s] << endl;
	}
	return 0;
}