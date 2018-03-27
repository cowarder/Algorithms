#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<vector<int>>dp;
		dp.resize(n + 1);
		vector<int>v;
		v.resize(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		for (int i = 0; i <= n; i++)dp[i].resize(41);
		for (int i = 1; i <= n; i++)	//前i个物体构成体积为0的方案
			dp[i][0] = 1;
		dp[0][0] = 1;
		for(int i=1;i<=n;i++)
			for (int j = 0; j <= 40; j++) {
				dp[i][j] = dp[i - 1][j];
				if (v[i] <= j)
					dp[i][j] += dp[i - 1][j - v[i]];
			}
		cout << dp[n][40] << endl;
	}
	return 0;
}