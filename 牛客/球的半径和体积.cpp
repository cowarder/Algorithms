#include<iostream>
#include<math.h>
#include <iomanip>
using namespace std;

int main() {
	int x1, y1, z1, x2, y2, z2;
	double radius, column;
	while (cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2) {
		radius = sqrt(pow((x1 - x2)*1.0, 2) + pow((y1 - y2)*1.0, 2) + pow((z1 - z2)*1.0, 2));
		column = 4.0*(acos(-1))*pow(radius, 3) / 3;
		cout << setiosflags(ios::fixed) << setprecision(3) << radius << " " << setiosflags(ios::fixed) << setprecision(3) << column << endl;
	}
	return 0;
}