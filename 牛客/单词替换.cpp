#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string>v;

void split(string s) {
	v.clear();
	v.resize(0);
	int index = s.find(' ');
	while(index!=-1){
		v.push_back(s.substr(0, index));
		s = s.substr(index+1, s.length() - index - 1);
		index = s.find(' ');
	}
	v.push_back(s);
}

int main() {
	string s;
	while (getline(cin, s)) {
		split(s);
		string s1, s2;
		cin >> s1 >> s2;
		for (int i = 0; i < v.size(); i++)
			if (v[i] == s1)
				v[i] = s2;
		bool first = true;
		string s = "";
		for (int i = 0; i < v.size(); i++)
			if (first) {
				first = false;
				s+=v[i];
			} else {
				s += " ";
				s += v[i];
			}
		cout << s << endl;
	}
	return 0;
}