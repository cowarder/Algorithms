#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int min(int a, int b) {
	if (a < b)return a;
	return b;
}

int main() {
	int M, N;
	vector<vector<int>>dp;
	vector<int>arr;
	while (cin >> M >> N) {
		dp.resize(0);
		dp.clear();
		arr.resize(0);
		dp.clear();
		arr.resize(N + 1);
		dp.resize(N + 1);
		for (int i = 1; i <= N; i++)
			cin >> arr[i];
		for (int i = 0; i <= N; i++)
			dp[i].resize(M + 1);
		for (int i = 1; i <= M; i++)
			dp[0][i] = N+1;
		dp[0][0] = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = M; j >= arr[i]; j--) {
				dp[i][j] = min(dp[i - 1][j] , dp[i - 1][j - arr[i]]+1);
			}
			for (int j = arr[i] - 1; j >= 0; j--)
				dp[i][j] = dp[i - 1][j];
		}
		if (dp[N][M] == (N+1))
			cout << 0 << endl;
		else
			cout << dp[N][M] << endl;
	}
	return 0;
}