#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main() {
	string a, b;
	while (cin >> a >> b) {
		int numA, numB;
		stringstream ss(a);
		ss >> numA;
		stringstream sa(b);
		sa >> numB;
		int sum1 = numA + numB;
		string sum = "";
		stringstream se;
		se << sum1;
		string sf;
		se >> sf;
		for (int i = sf.length() - 1; i >= 0; i--)
			sum += sf[i];
		stringstream sm(sum);
		sm >> sum1;
		string A = "";
		string B = "";
		for (int i = a.length() - 1; i >= 0; i--)
			A += a[i];
		for (int i = b.length() - 1; i >= 0; i--)
			B += b[i];
		int numa, numb;
		stringstream sb(A);
		sb >> numa;
		stringstream sc(B);
		sc >> numb;
		int sum2 = numa + numb;
		if (sum1 == sum2)
			cout << numA+numB << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}