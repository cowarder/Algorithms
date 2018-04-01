#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//运用两次最大子序列长度算法，求出每个位置的两端最大子序列长度（包含当前值）
//减去两个最大子序列长度+1，得到的就是当前位置为最高点构成的队伍的长度
//这里需要注意开始构建子序列的时候，要把大于当前值的数全部去掉

vector<int>v;

int bin(int index) {
	int n = v.size() - 1;
	vector<int>left;
	vector<int>right;
	left.push_back(v[index]);
	right.push_back(v[index]);
	for (int i = index - 1; i >= 1; i--)
		if (v[i] < v[index])
			left.push_back(v[i]);
	for (int i = index + 1; i <= n; i++)
		if (v[i] < v[index])
			right.push_back(v[i]);
	vector<int>leftMax, rightMax;
	leftMax.resize(left.size());
	rightMax.resize(right.size());
	leftMax[0] = 1;
	rightMax[0] = 1;
	int maxLeftLen = 0;
	int maxRightLen = 0;

	for (int i = 1; i < left.size(); i++) {
		maxLeftLen = 0;
		for (int j = 0; j < i; j++) {
			if (left[j] > left[i])
				if (maxLeftLen < (leftMax[j] + 1))
					maxLeftLen = leftMax[j] + 1;
		}
		leftMax[i] = max(1, maxLeftLen);
	}

	maxLeftLen = *max_element(leftMax.begin(),leftMax.end());

	for (int i = 1; i < right.size(); i++) {
		maxRightLen = 0;
		for (int j = 0; j < i; j++) {
			if (right[j] > right[i])
				if (maxRightLen < (rightMax[j] + 1))
					maxRightLen = rightMax[j] + 1;
		}
		rightMax[i] = max(1, maxRightLen);
	}
	maxRightLen = *max_element(rightMax.begin(),rightMax.end());

	return n-(maxLeftLen + maxRightLen - 1);
}

int main() {
	int n;
	while (cin >> n) {
		v.clear();
		v.resize(n+1);
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		int minLen = n;
		for (int i = 1; i <= n; i++) {
			int num = bin(i);
			if (num < minLen)
				minLen = num;
		}
		cout << minLen << endl;
	}
	return 0;	
}