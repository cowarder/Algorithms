#include<iostream>
using namespace std;
int main() {
	double storerate;
	double houseprice;
	double houserate;
	double n;
	double k;
	while (cin >> n >> k) {
		houseprice = 200;
		storerate = 100.0;
		houserate = k;
		int year = 1;
		double store = n;
		while (storerate > houserate&&store < houseprice) {
			year++;
			houseprice *= (1.0*(100 + k) / 100);
			store += n;
			storerate = n / store*100;
		}
		if (store >= houseprice)
			cout << year << endl;
		else
			cout << "Impossible" << endl;
	}
	return 0;
}