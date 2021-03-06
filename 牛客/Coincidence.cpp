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
		for (int i = 0; i<len1; i++)
			for (int j = 0; j < len2; j++) {
				if (s1[i] == s2[j]) {
					if (i > 0 && j > 0)
						dp[i][j] = dp[i - 1][j - 1] + 1;
					else
						dp[i][j] = 1;
				} else {
					if (i > 0 && j > 0)
						dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
					else
						dp[i][j] = 0;
				}
			}
		cout << dp[len1-1][len2-1] << endl;
	}
	return 0;
}