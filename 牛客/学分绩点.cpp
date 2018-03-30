#include<iostream>
#include<vector>
#include<numeric>
#include<iomanip>
using namespace std;

int main() {
	int n;
	vector<double>point;
	vector<double>grade;
	while (cin >> n) {
		point.clear();
		grade.clear();
		point.resize(n);
		grade.resize(n);
		for (int i = 0; i < n; i++)
			cin >> point[i];
		for (int i = 0; i < n; i++) {
			cin >> grade[i];
			if (grade[i] >= 90)
				grade[i] = 4.0;
			else if (grade[i] >= 85)
				grade[i] = 3.7;
			else if (grade[i] >= 82)
				grade[i] = 3.3;
			else if (grade[i] >= 78)
				grade[i] = 3.0;
			else if (grade[i] >= 75)
				grade[i] = 2.7;
			else if (grade[i] >= 72)
				grade[i] = 2.3;
			else if (grade[i] >= 68)
				grade[i] = 2.0;
			else if (grade[i] >= 64)
				grade[i] = 1.5;
			else if (grade[i] >= 60)
				grade[i] = 1.0;
			else
				grade[i] = 0.0;
		}
		vector<double>pointgrade;
		pointgrade.resize(n);
		for (int i = 0; i < n; i++)
			pointgrade[i] = grade[i] * point[i];
		double a = accumulate(pointgrade.begin(), pointgrade.end(),0.0);
		double b = accumulate(point.begin(), point.end(),0.0);
		cout << setiosflags(ios::fixed) << setprecision(2) << a / b << endl;
	}
}