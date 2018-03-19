#include<iostream>
#include<map>
#include<vector>
#include<iomanip>
using namespace std;

class BigInteger {
public:
	vector<int>v;

	BigInteger() {
		v.clear();
		v.resize(0);
	}


	
	void set(int num) {
		v.clear();
		v.resize(0);
		while (num > 0) {
			v.push_back(num % 10000);
			num /= 10000;
		}
	}


	BigInteger operator*(const BigInteger in) const{
		BigInteger num;
		//in.display();
		int i = 0;
		int flag = 0;
		while (i < v.size() && i < in.v.size()) {
			int tmp = v[i] * in.v[i]+flag;
			flag = tmp / 10000;
			tmp %= 10000;
			num.v.push_back(tmp);
			i++;
		}
		while (i < v.size()) {
			int tmp = (v[i] + flag);
			flag = tmp / 10000;
			tmp %= 10000;
			num.v.push_back(tmp);
			i++;
		}
		while (i < in.v.size()) {
			int tmp = (in.v[i] + flag);
			flag = tmp / 10000;
			tmp %= 10000;
			num.v.push_back(tmp);
			i++;
		}
		if (flag > 0)
			num.v.push_back(flag);
		//num.display();
		return num;
	}

	void display() {
		for (int i = v.size() - 1; i >= 0; i--)
			if (i == v.size() - 1)
				cout << v[i];
			else
				cout << setfill('0') << setw(4);
		cout << endl;
	}
};

int root(int x, int y, int k) {
	BigInteger num;
	num.set(x);
	BigInteger result;
	result.set(1);
	for (int i = 1; i <= y; i++) {
		result = result* num;
	}
	result.display();
	return 1;
}

int main() {
	int x, y, k;
	while (cin >> x >> y >> k) {
		root(x, y, k);
	}
	return 0;
}
