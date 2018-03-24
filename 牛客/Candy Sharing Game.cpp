#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>v;
int main() {
	int n;
	while (cin >> n) {
		v.clear();
		v.resize(0);
		v.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		int max;
		int min;
		int round = 0;
		while(true){
			min = *min_element(v.begin(), v.end());
			max = *max_element(v.begin(), v.end());
			//for (int i = 0; i < n; i++)
			//	cout << v[i] << " ";
			//cout << endl;
			if (min == max)
				break;
			else {
				round++;
				vector<int>half;
				half.resize(n);
				for (int i = 0; i < n; i++)
					half[i] = v[i] / 2;
				for (int i = 1; i < n; i++) {
					v[i] -= half[i];
					v[i] += half[i - 1];
				}
				v[0] -= half[0];
				v[0] += half[n-1];
			}
			for (int i = 0; i < n; i++)
				if (v[i] % 2 == 1)
					v[i]++;
		}
		cout <<round<<" "<< min << endl;
	}
	return 0;
}