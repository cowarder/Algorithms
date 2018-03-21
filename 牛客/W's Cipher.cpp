#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int>group1, group2, group3;

void cutGroup(string& s, int k1, int k2, int k3) {
	group1.clear();
	group2.clear();
	group3.clear();
	group1.resize(0);
	group2.resize(0);
	group3.resize(0);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a'&&s[i] <= 'i')
			group1.push_back(i);
		else if (s[i] >= 'j'&&s[i] <= 'r')
			group2.push_back(i);
		else
			group3.push_back(i);
	}
	k1 = k1%group1.size();
	k2 = k2%group2.size();
	k3 = k3%group3.size();
	vector<int>new1(group1.begin() + k1, group1.end());
	for (int i = 0; i < k1; i++)
		new1.push_back(group1[i]);
	vector<int>new2(group2.begin() + k2, group2.end());
	for (int i = 0; i < k2; i++)
		new2.push_back(group2[i]);
	vector<int>new3(group3.begin() + k3, group3.end());
	for (int i = 0; i < k3; i++)
		new3.push_back(group3[i]);
	string news = s;
	for (int i = 0; i < group1.size(); i++)
		news[new1[i]] = s[group1[i]];
	for (int i = 0; i < group2.size(); i++)
		news[new2[i]] = s[group2[i]];
	for (int i = 0; i < group3.size(); i++)
		news[new3[i]] = s[group3[i]];
	cout << news << endl;
}

int main() {
	string s;
	int k1, k2, k3;
	while (cin >> k1 >> k2 >> k3) {
		if (k1 == k2&&k2 == k3 &&k1 == 0)
			break;
		cin >> s;
		cutGroup(s, k1, k2, k3);
	}
	return 0;
}