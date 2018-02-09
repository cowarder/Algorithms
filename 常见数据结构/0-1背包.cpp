#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node {
public:
	int time;
	int value;
};
int main() {
	vector<Node>v;
	vector<int>dp;
	int T, M;
	while (cin >> T >> M) {
		v.clear();
		dp.clear();
		v.resize(M);
		dp.resize(T + 1);
		for (int i = 0; i < M; i++)
			cin >> v[i].time >> v[i].value;
		for (int i = 0; i <= T; i++)
			dp[i] = 0;
		for (int i = 0; i <M; i++)
			for (int j = T; j >= v[i].time; j--)
				dp[j] = max(dp[j], dp[j - v[i].time] + v[i].value);
		cout << dp[T] << endl;
	}
	return 0;
}