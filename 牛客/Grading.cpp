#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	double p, t, g1, g2, g3, gj;
	while (cin >> p >> t >> g1 >> g2 >> g3 >> gj) {
		if (abs(g1 - g2) <= t)
			cout << setiosflags(ios::fixed) << setprecision(1) << (g1 + g2) / 2 << endl;
		else if (abs(g3 - g1) <= t&&abs(g3 - g2) <= t)
			cout << setiosflags(ios::fixed) << setprecision(1) << (g1 > g2&g1 > g3 ? g1 : (g2 > g3 ? g2 : g3)) << endl;
		else if (abs(g3 - g1) > t&&abs(g3 - g2) > t)
			cout << setiosflags(ios::fixed) << setprecision(1) << gj << endl;
		else
			cout << setiosflags(ios::fixed) << setprecision(1) << (g3 + (abs(g3 - g1) > (g3 - g2) ? g2 : g1)) / 2 << endl;
	}
	return 0;
}