#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;

int main() {
	int n;
	string s;
	while (cin >> n) {
		set<int>se;
		for (int i = 0; i < n; i++) {
			cin >> s;
			stringstream ss(s);
			int num;
			ss >> num;
			se.insert(num);
		}
		bool first = true;
		for (int i : se)
			if (first == true) {
				cout << i ;
				first = false;
			} else
				cout << " " << i;
	}
	return 0;
}