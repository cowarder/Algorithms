#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node {
public:
	int value;
	int cost;
	Node(){
		cost = 0;
		value = 0;
	}
};


int main() {
	vector<Node>v;
	vector<vector<int>>dp;
	int n;
	int cost;
	while (cin >>cost>> n) {
		v.clear();
		dp.clear();
		v.resize(0);
		dp.resize(0);
		v.resize(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> v[i].cost >> v[i].value;
		dp.resize(n + 1);
		for (int i = 0; i <= n; i++)
			dp[i].resize(cost+1);
		for (int i = 0; i <= cost; i++)dp[0][i] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = cost; j >= v[i].cost; j--)
				//dp[i][j]表示在总体积不超过j的情况下，前i个物体可以达到的最大价值
				dp[i][j] = max(dp[i - 1][j - v[i].cost] + v[i].value, dp[i - 1][j]);
			for (int j = v[i].cost - 1; j >= 0; j--)
				dp[i][j] = dp[i - 1][j];
		}
		cout << dp[n][cost] << endl;
	}
	return 0;
}