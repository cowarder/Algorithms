#include<iostream>
#include<string>
#include<stack>
#include<map>
#include<vector>
#include<sstream>
#include<iomanip>
using namespace std;

map<string, int>prio{
	{"+",1},
	{"-",1},
	{"*",2},
	{"/",2}
};

bool isOp(string c) {
	if (c == "+" || c == "-" || c == "*" || c == "/")
		return true;
	return false;
}

bool isNum(char c) {
	if (c >= '0'&&c <= '9')
		return true;
	return false;
}

double cal(double a, string op, double b) {
	if (op == "+")
		return a + b;
	else if (op == "-")
		return a - b;
	else if (op == "*")
		return a*b;
	else
		return a / b;
}

int main() {
	string formula;
	while (getline(cin , formula)) {
		if (formula == "0")
			break;
		int index = 0;
		vector<string>s;
		stack<string>ops;
		while (index < formula.length()) {
			int end = index;
			while (isNum(formula[end]))end++;
			string num = formula.substr(index, end - index);
			//cout << num << endl;
			s.push_back(num);
			if (end < formula.length()) {
				end++;
				string op = formula.substr(end,1);
				//cout << op << endl;
				while (!ops.empty() && prio[op] <= prio[ops.top()]) {
					string top = ops.top();
					s.push_back(top);
					ops.pop();
				}
				ops.push(op);
			}
			end += 2;
			index = end;
		}
		while (!ops.empty()) {
			s.push_back(ops.top());
			ops.pop();
		}
		double num;
		stack<double>result;
		for (int i = 0; i < s.size(); i++) {
			if (isOp(s[i])) {
				double a = result.top();
				result.pop();
				double b = result.top();
				result.pop();
				double calresult = cal(b, s[i], a);
				result.push(calresult);
			} else {
				stringstream ss(s[i]);
				double d;
				ss >> d;
				result.push(d);
			}
		}
		cout << setiosflags(ios::fixed)<<setprecision(2)<<result.top() << endl;
	}
	return 0;
}