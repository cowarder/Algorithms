#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node {
public:
	int weight;
	int value;
};

int main() {
	int T, M;
	while (cin >> T >> M) {
		vector<vector<int>>dp;
		vector<Node>v;
		dp.resize(M + 1);
		for (int i = 0; i < dp.size(); i++)
			dp[i].resize(T + 1);
		v.resize(M + 1);
		for (int i = 1; i <= M; i++)
			cin >> v[i].weight >> v[i].value;
		for (int i = 0; i <= T; i++)
			dp[0][i] = 0;
		for (int i = 1; i <= M; i++) {
			for (int j = T; j >= v[i].weight; j--)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].weight] + v[i].value);
			for (int j = v[i].weight - 1; j >= 1; j--)
				dp[i][j] = dp[i - 1][j];
		}
		cout << dp[M][T] << endl;
	}
	return 0;	
}