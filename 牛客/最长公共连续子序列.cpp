#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	int k;
	string s1, s2;
	while (cin >> s1 >> s2) {
		int len1 = s1.length();
		int len2 = s2.length();
		vector<vector<int>>dp;
		dp.resize(len1);
		for (int i = 0; i < len1; i++)
			dp[i].resize(len2);
		int maxlen = 0;
		for (int i = 0; i<len1; i++)
			for (int j = 0; j < len2; j++) {
				if (s1[i] == s2[j]) {
					if (i > 0 && j > 0)
						dp[i][j] = dp[i - 1][j - 1] + 1;
					else
						dp[i][j] = 1;
				} 
				if (dp[i][j] > maxlen)
					maxlen = dp[i][j];
			}
		cout << maxlen << endl;
	}
	return 0;
}