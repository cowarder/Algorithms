#include<iostream>
#include<map>
using namespace std;

map<int, int>run{
	{1,31},
	{2,29},
	{3,31},
	{4,30},
	{5,31},
	{6,30},
	{7,31},
	{8,31},
	{9,30},
	{10,31},
	{11,30},
	{12,31}
};

map<int, int>ping{
	{ 1,31 },
	{ 2,28 },
	{ 3,31 },
	{ 4,30 },
	{ 5,31 },
	{ 6,30 },
	{ 7,31 },
	{ 8,31 },
	{ 9,30 },
	{ 10,31 },
	{ 11,30 },
	{ 12,31 }
};

bool isRun(int year) {
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		return true;
	return false;
}

int main() {
	int y, m, d;
	while (cin >> y >> m >> d) {
		int days = 0;
		if (isRun(y))
			for (int i = 1; i < m; i++)
				days += run[i];
		else
			for (int i = 1; i < m; i++)
				days += ping[i];
		days += d;
		cout << days << endl;
	}
	return 0;
}