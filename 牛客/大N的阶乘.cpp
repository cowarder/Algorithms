#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

class BigInteger {
public:
	vector<int>v;
	void set(int x) {
		v.clear();
		v.resize(0);
		do {
			v.push_back(x%10000);
			x /= 10000;
		} while (x != 0);
	}

	void output() {
		for (int i = v.size() - 1; i >= 0; i--) {
			if (i != v.size() - 1)
				cout << setw(4) << setfill('0') << v[i];
			else
				cout << v[i];
		}
		cout << endl;
	}

	BigInteger operator*(int x) const{
		int jin = 0;
		BigInteger res;
		for (int i = 0; i < v.size(); i++) {
			res.v.push_back((x*v[i] + jin) % 10000);
			jin = (x*v[i] + jin) / 10000;
		}
		if (jin > 0)
			res.v.push_back(jin);
		return res;
	}
};

int main() {
	int N;
	while (cin >> N) {
		BigInteger a;
		a.set(1);
		for (int i = 1; i <= N; i++)
			a =a* i;
		a.output();
	}
	return 0;

}