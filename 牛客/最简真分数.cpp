#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int gcd(int a, int b) {
	while (b) {
		a = a%b;
		swap(a, b);
	}
	return a;
}
vector<int>v;
int main() {
	int n;
	while (cin >> n) {
		v.clear();
		v.resize(0);
		v.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		int num = 0;
		for(int i=0;i<n;i++)
			for (int j = i + 1; j < n; j++)
				if (gcd(v[i], v[j]) == 1)
					num++;
		cout << num << endl;
	}
	return 0;
}