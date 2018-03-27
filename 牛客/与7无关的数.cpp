#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool judge(int num) {
	if (num % 7 == 0)
		return true;
	else
		while (num > 0) {
			if (num % 10 == 7)
				return true;
			num /= 10;
		}
	return false;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int>v;
		for (int i = 1; i <= n; i++)
			if (!judge(i))
				v.push_back(pow(i, 2));
		int result = 0;
		for (int i = 0; i < v.size(); i++)
			result += v[i];
		cout << result << endl;
	}
	return 0;
}