#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

map<string, int>m{
	{"zero",0},
	{"one",1},
	{"two",2},
	{"three",3},
	{"four",4},
	{"five",5},
	{"six",6},
	{"seven",7},
	{"eight",8},
	{"nine",9}
};

bool isAlpha(char c) {
	if (c >= 'a'&&c <= 'z')
		return true;
	return false;
}

int main() {
	string line;
	while (getline(cin, line)) {
		line = line.substr(0, line.length() - 2);
		if (line == "zero + zero")
			break;
		vector<int>v1;
		vector<int>v2;
		int begin, end;
		begin = end = 0;
		while (begin < line.length()) {
			if (!isAlpha(line[begin]))
				break;
			while (isAlpha(line[end]))end++;
			string num = line.substr(begin, end - begin);
			v1.push_back(m[num]);
			end += 1;
			begin = end;
		}
		begin += 2;
		end = begin;
		while (begin < line.length()) {
			while (isAlpha(line[end]))end++;
			string num = line.substr(begin, end - begin);
			v2.push_back(m[num]);
			end += 1;
			begin = end;
		}
		int num1 = 0;
		int i = 0;
		while (i<v1.size()&&v1[i] == 0)i++;
		if (i != v1.size())
			while (i < v1.size()) {
				num1 *= 10;
				num1 += v1[i];
				i++;
			}
		int num2 = 0;
		i = 0;
		while (i<v2.size() && v2[i] == 0)i++;
		if (i != v2.size())
			while (i < v2.size()) {
				num2 *= 10;
				num2 += v2[i];
				i++;
			}
		cout << num1 + num2 << endl;
	}
	return 0;
}