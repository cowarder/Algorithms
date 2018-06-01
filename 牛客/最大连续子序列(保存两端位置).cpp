#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//利用动态规划的思想，只要求出和之后，只要当前的位置的和大于0，就说明当前
//值对后面的求和产生贡献，在一个就是一定要注意全是负数的情况，这样两端的位置都是相同的

int max(int a, int b) {
	return a > b ?  a : b;
}

int main() {
	int k;
	while (cin >> k) {
		if (k == 0)
			break;
		vector<int>v;
		v.resize(k);
		for (int i = 0; i < k; i++)
			cin >> v[i];
		vector<int>sum;
		sum.resize(k);
		sum[0] = v[0];
		for (int i = 1; i < k; i++)
			sum[i] = max(sum[i - 1] + v[i], v[i]);
		int index = -1;
		int maxsum = -10000;
		for(int i=0;i<k;i++)
			if (sum[i] > maxsum) {
				maxsum = sum[i];
				index = i;
			}
		int right = index;
		int left = right;
		if (sum[right] > 0) {
			while (left >= 0 && sum[left] > 0) {
				left--;
			}
			left++;
		}else
			left = right;
		cout << sum[index] << " " << v[left] << " "<<v[right] << endl;

	}
	return 0;
}