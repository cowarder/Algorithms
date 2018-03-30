#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int N;
vector<vector<int>>v;

int getMaxVecSum(vector<int>a) {
	vector<int>dp;
	dp.resize(a.size());
	dp[0] = a[0];
	for (int i = 1; i < dp.size(); i++)
		dp[i] = max(dp[i - 1] + a[i], a[i]);
	return *max_element(dp.begin(), dp.end());
}

vector<int> getSubVec(int i, int j) {
	vector<int>ans;
	ans.resize(N);
	for (int x = i; x <= j; x++)
		for (int y = 0; y < N; y++)
			ans[y] += v[x][y];
	return ans;
}

void getMaxMatSum() {
	int maxsum = INT_MIN;
	int temp;
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
			if ((temp = getMaxVecSum(getSubVec(i, j))) > maxsum)
				maxsum = temp;
	cout << maxsum << endl;
}

int main() {
	while (cin >> N) {
		v.resize(N);
		for (int i = 0; i < N; i++)
			v[i].resize(N);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> v[i][j];
		getMaxMatSum();
	}
	return 0;
}