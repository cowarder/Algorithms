#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

class Node {
public:
	char c;
	int next;
};

vector<Node>v(100000);

int main() {
	int add1,add2;
	int n;
	while (cin >> add1 >> add2 >> n) {
		for (int i = 0; i < 100000; i++)v[i].next = -1;
		int start, next;
		char c;
		for (int i = 1; i <= n; i++) {
			cin >> start >> c >> next;
			v[start].c = c;
			v[start].next = next;
		}
		int add1cp = add1;
		int add2cp = add2;
		string s1 = "";
		string s2 = "";
		while (add1cp != -1) {
			s1 += v[add1cp].c;
			add1cp = v[add1cp].next;
		}
		while (add2cp != -1) {
			s2 += v[add2cp].c;
			add2cp = v[add2cp].next;
		}
		//cout << s1 << endl;
		//cout << s2 << endl;
		string common = "";
		int index1 = s1.length() - 1;
		int index2 = s2.length() - 1;
		while (s1[index1] == s2[index2]) {
			common = s1[index1] + common;
			index1--;
			index2--;
		}
		if (common == "")
			cout << -1 << endl;
		else {
			string newStr = "";
			while (newStr.length() < (s1.length() - common.length())) {
				newStr = (v[add1].c + newStr);
				add1 = v[add1].next;
			}
			cout << setfill('0')<<setw(5)<<add1 << endl;
		}
	}
	return 0;
}