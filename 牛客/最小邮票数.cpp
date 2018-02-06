#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int M, N;
	int i, j;
	vector<int>dp;
	vector<int>arr;
	while (cin >> M >> N) {
		dp.resize(M + 1);
		arr.resize(N);
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		for (int i = 0; i <= M; i++)
			dp[i] = N + 1;
		dp[0] = 0;
		for (int i = 0; i < N; i++) 
			for (int j = M; j >= arr[i]; j--)
				dp[j] = min(dp[j], dp[j - arr[i]] + 1);
		if (dp[M] <= N)
			cout << dp[M] << endl;
		else
			cout << 0 << endl;
		for (int i = 0; i <= M; i++)
			cout << dp[i];
	}
	return 0;
}