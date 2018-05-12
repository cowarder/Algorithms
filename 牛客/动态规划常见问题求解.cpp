(1)最长递增子序列
原理：
f[1]=1
f[i]=max(1,f[j]+1)(j<i,v[j]<v[i])
f[i]表示递增子序列以v[i]结束时它的最长长度

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int>v{ 0,2,3,4,4,3,2,5,34,4,6,123 };
	vector<int>num;
	num.resize(v.size());
	num[0] = 1;
	for (int i = 2; i < v.size(); i++) {
		vector<int>n;
		n.push_back(1);
		for (int j = 0; j < i; j++)
			if (v[j] <= v[i])
				n.push_back(num[j] + 1);
		num[i] = *max_element(n.begin(), n.end());
	}
	cout << *max_element(num.begin(), num.end())<<endl;
	return 0;
}


(2)最长公共子序列
原理：
dp[i][j]表示s1前i个字符和s2前j个字符组成的两个前缀字符串的最长公共子串长度

dp[0][i]=0(0=<i<=m)
dp[j][0]=0(0=<j<=n)
dp[i][j]=dp[i-1][j-1]+1	(s[i]==s[j])
dp[i][j]=max{dp[i-1][j],dp[i][j-1]}	(s[i]!=s[j])	

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s1 = "asdfuuu";
	string s2 = "dfummm";
	vector<vector<int>>dp;
	int m = s1.length();
	int n = s2.length();
	dp.resize(m + 1);
	for (int i = 0; i <= m; i++)
		dp[i].resize(n + 1);
	for (int i = 0; i <= m; i++)
		dp[i][0] = 0;
	for (int j = 0; j <= n; j++)
		dp[0][j] = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (s1[i] == s2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	cout << dp[m][n] << endl;
	return 0;
}

(3)最长连续公共子序列
原理：
dp[i][j]表示以s1[i]，s2[j]为结尾的字符串的公共长度

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s1 = "asdfuuuu";
	string s2 = "dfuummm";
	vector<vector<int>>dp;
	int m = s1.length();
	int n = s2.length();
	dp.resize(m + 1);
	for (int i = 0; i <= m; i++)
		dp[i].resize(n + 1);
	for (int i = 0; i <= m; i++)
		dp[i][0] = 0;
	for (int j = 0; j <= n; j++)
		dp[0][j] = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (s1[i-1] == s2[j-1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
	int max = -1;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (dp[i][j] > max)
				max = dp[i][j];
	cout << max << endl;
	return 0;
}


(4)最大连续子序列的和
原理：
dp[i]表示以第i个数字为结尾的连续子序列的和dp[i]=max{dp[i-1]+a[i],a[i]}
示例程序:

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	vector<int>v{ 1,2,3,-5,3,5,2,-7 };
	vector<int>sum;
	sum.resize(8);
	sum[0] = v[0];
	for (int i = 1; i < v.size(); i++)
		sum[i] = max(sum[i - 1] + v[i], v[i]);
	cout << *max_element(sum.begin(), sum.end());
	return 0;
}


(5)最大子序列和
int findMaxSum(vector<int>v){
	int sum=0;
	int maxSum=0;
	for(int i=0;i<v.size();i++){
		sum+=v[i];
		if(sum>maxSum)
			maxSum=sum;
		else if(sum<0)
			sum=0;
	}
	cout<<maxSum<<endl;
}


(7)最大子序列和，但是有一个限定最大值，就转换为动态规划问题中的背包问题
对于每个变量来说，它的value同时也是它的cost
dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - intValue[i]] + intValue[i]);
当遇到背包中的值为double类型的时候，可以将其乘以10的次方，转换为整数


(6)0-1背包问题要注意vector<vector<int>>dp的时候不一定是0！！！，必须要初始化
原理：
dp[i][j]表示总体积不超过j的条件下，前i件物品可以达到的最大价值

点菜问题：
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node {
public:
	int value;
	int cost;
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
		//这里当时调试了几次，由于将cost写为n的原因，初始化过程必不可少
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

()