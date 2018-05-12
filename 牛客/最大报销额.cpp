#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;

vector<double>value;

double max(double a, double b) {
	if (a > b)
		return a;
	return b;
}

int main() {
	double q;
	int n;
	while (cin >> q >> n) {
		if (n == 0)
			break;
		value.clear();
		value.resize(0);
		int num;
		string price;
		for (int i = 0; i < n; i++) {
			cin >> num;
			double totalValue = 0;
			bool usable = true;
			for (int j = 0; j < num; j++) {
				cin >> price;
				if (price[0] != 'A'&&price[0] != 'B'&&price[0] != 'C') {
					usable = false;
					continue;
				}
				price = price.substr(2);
				stringstream ss(price);
				double dPrice=0;
				ss >> dPrice;
				if (dPrice > 600)
					usable = false;
				totalValue += dPrice;
			}
			if (totalValue > 1000)
				usable = false;
			if (usable == true&&totalValue<=q)
				value.push_back(totalValue);
		}
		int maxPrice = q * 100;
		vector<int>intValue;
		intValue.resize(value.size());
		for (int i = 0; i < value.size(); i++)
			intValue[i] = value[i] * 100;
		vector<vector<int>>dp;
		dp.resize(intValue.size()+1);
		for (int i = 0; i <= intValue.size(); i++)
			dp[i].resize(maxPrice + 1);
		for (int i = 0; i <= maxPrice;i++)
			dp[0][i] = 0;
		for (int i = 1; i <= intValue.size(); i++)
			for (int j = maxPrice; j >= intValue[i-1]; j--) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - intValue[i-1]] + intValue[i-1]);
			}
		cout << setiosflags(ios::fixed) << setprecision(2)<<dp[intValue.size()][maxPrice]/100.0 << endl;
	}
	return 0;
}