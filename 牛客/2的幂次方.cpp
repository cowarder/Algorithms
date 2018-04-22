#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

string conversion(int m,string s,int n) {
	int len = s.length();
	int k;
	string result = "";
	for (int i = 0; i < len;) {
		k = 0;
		for (int j = i; j < len; j++) {
			int t = (k*m + s[j] - '0') % n;
			s[j] = (k*m + s[j] - '0') / n+'0';
			k = t;
		}
		result += char(k + '0');
		while (s[i] == '0')i++;
	}
	//cout << result << endl;
	string formula="";
	bool first = true;
	for (int i = result.length() - 1; i >= 0; i--) {
		if (result[i] == '1') {
			if (first) {
				first = false;
			} else
				formula += "+";
			formula += "2";
			if (i != 1) {
				formula += "(";
				stringstream ss;
				ss << i;
				string num;
				ss >> num;
				formula += num;
				formula += ")";
			}
		}
	}
	return formula;
}

string formulaTrans(string s) {
	bool found = true;
	while (found == true) {
		found = false;
		for (int i = 0; i < s.length(); i++) {
			string sub = "";
			int j = i;
			while (s[j] >= '0'&&s[j] <= '9') {
				sub += s.substr(j, 1);
				j++;
			}
			sub = conversion(10, sub, 2);
			//cout << sub<<endl;
			if ((i != j&&(j-i)>1)||((j-i)==1&&s[i]!='0'&&s[i]!='2')) {
				found = true;
				s = s.replace(i, j - i, sub);
				//cout << sub << " " << s << endl;
			}
			i = j;
		}
	}
	
	return s;
}

int main() {
	string s;
	while (cin >> s) {
		//cout << conversion(10, s, 2)<<endl;
		cout << formulaTrans(s) << endl;
	}
	return 0;
}