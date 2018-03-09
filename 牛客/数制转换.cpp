#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<map>
using namespace std;
map<char, int>in{
	{'0',0},
	{'1',1},
	{'2',2},
	{'3',3},
	{'4',4},
	{'5',5},
	{'6',6},
	{'7',7},
	{'8',8},
	{'9',9},
	{'A',10},
	{'B',11},
	{'C',12},
	{'D',13},
	{'E',14},
	{'F',15},
	{'a',10},
	{'b',11},
	{'c',12},
	{'d',13},
	{'e',14},
	{'f',15}
};

map<int,string>out{
	{0,"0"},
	{1,"1"},
	{2,"2"},
	{3,"3"},
	{4,"4"},
	{5,"5"},
	{6,"6"},
	{7,"7"},
	{8,"8"},
	{9,"9"},
	{10,"A"},
	{11,"B"},
	{12,"C"},
	{13,"D"},
	{14,"E"},
	{15,"F"}
};

long numToTen(string s,int system) {
	int index = 0;
	while (s[index] == '0') { index++; }
	s = s.substr(index, s.length() - index);
	long result = 0;
	int flag = 1;
	for (int i = (s.length() - 1); i >= 0; i--) {
		result += flag*in[s[i]];
		flag *= system;
	}
	return result;
}

string tenToNum(long num, int system) {
	if (num == 0)
		return "0";
	string s = "";
	stack<string>st;
	while (num > 0) {
		st.push(out[num%system]);
		num /= system;
	}
	while (!st.empty()) {
		s += st.top();
		st.pop();
	}
	return s;
}

int main() {
	int a, b;
	string s;
	while (cin >> a >> s >> b) {
		long num = numToTen(s, a);
		string s = tenToNum(num, b);
		cout << s << endl;
	}

	return 0;
}