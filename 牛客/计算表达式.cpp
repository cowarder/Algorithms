#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<map>
#include<sstream>
using namespace std;

//存放优先级
map<string,int>pri{
	{"+",1},
	{"-",1},
	{"*",2},
	{"/",2}
};

bool isOperator(string c) {
	if (c == "+" ||c== "-" ||c== "*" ||c== "/")
		return true;
	return false;
}

double operate(double a, double b, string op) {
	if (op == "+")
		return a + b;
	else if (op == "-")
		return a - b;
	else if (op == "*")
		return a*b;
	else if (op == "/")
		return a / b;
	return 0;
}

bool isNum(string str) {
	stringstream ss(str);
	double d;
	if (ss >> d)
		return true;
	return false;
}

int main() {
	string s;
	string flag = "";
	while (cin >> s) {
		stack<string>op;
		vector<string>v;

		//中缀转后缀
		for (int i = 0; i < s.length(); i++) {
			if (isOperator(s.substr(i,1))) {
				v.push_back(flag);
				flag = "";
				if (op.empty()||(!op.empty()&&pri[s.substr(i, 1)] > pri[op.top()]))
					op.push(s.substr(i, 1));
				else {
					while (!op.empty() && pri[s.substr(i, 1)] <= pri[op.top()]) {
						v.push_back(op.top());
						op.pop();
					}
					op.push(s.substr(i, 1));
				}
			}
			else
				flag +=s.substr(i,1);
		}
		v.push_back(flag);
		while (!op.empty()) {
			v.push_back(op.top());
			op.pop();
		}


		stack<double>result;
		for (int i = 0; i < v.size(); i++) {
			if (isNum(v[i])) {
				stringstream ss(v[i]);
				double d;
				ss >> d;
				result.push(d);
			} else {
				double b = result.top();
				result.pop();
				double a = result.top();
				result.pop();
				double c = operate(a, b,v[i]);
				result.push(c);
			}
		}
		cout << result.top() << endl;
	}
	return 0;
}