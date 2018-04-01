#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s;
	while (getline(cin,s)) {
		map<string, string>m;
		string alpha = "";
		for (int i = 0; i < s.length(); i++) {
			if ((s[i] <= 'z'&&s[i] >= 'a') || (s[i] <= 'Z'&&s[i] >= 'A')) {
				string ss="";
				if (s[i] >= 'a'&&s[i] <= 'z')
					ss += s[i];
				else
					ss += char(s[i] + 32);
				m[ss] += s.substr(i, 1);
				alpha += s[i];
			}
		}
		string lowerAlpha=alpha;
		transform(lowerAlpha.begin(), lowerAlpha.end(), lowerAlpha.begin(), ::tolower);
		sort(lowerAlpha.begin(), lowerAlpha.end());
		//cout << lowerAlpha;
		for (int i = 0; i < lowerAlpha.length(); i++) {
			int j = i;
			string preChar="";
			preChar += lowerAlpha[i];
			while (lowerAlpha[j] == lowerAlpha[i])j++;
			lowerAlpha.replace(i, j - i, m[preChar]);
			i = j - 1;
			//cout << lowerAlpha << endl;
		}
		int index = 0;
		for (int i = 0; i < s.length(); i++)
			if ((s[i] <= 'z'&&s[i] >= 'a') || (s[i] <= 'Z'&&s[i] >= 'A'))
				s[i] = lowerAlpha[index++];
		cout << s << endl;
	}
	return 0;	
}