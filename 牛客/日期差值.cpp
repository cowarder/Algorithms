#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

map<string, int> getMonth{
	{"January",1 },
	{"February",2},
	{"March",3},
	{"April",4},
	{"May",5},
	{"June",6},
	{"July",7},
	{"August",8},
	{"September",9},
	{"October",10},
	{"November",11},
	{"December",12}
};

map<int, int> ping{
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

map<int, int> run{
	{ 1,31 },
	{ 2,29 },
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
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	else
		return false;
}

vector<string>week{"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

int main() {
	int date1, date2;
	while (cin >>date1>>date2) {
		int days1 = 0;
		int days2 = 0;
		int year1 = date1 / 10000;
		int year2 = date2 / 10000;
		int mon1 = (date1 / 100) % 100;
		int mon2 = (date2 / 100) % 100;
		int day1 = date1 % 100;
		int day2 = date2 % 100;

		for (int i = 999; i < year1; i++)
			if (isRun(i))
				days1 += 366;
			else
				days1 += 365;
		if (isRun(year1))
			for (int i = 1; i < mon1; i++)
				days1 += run[i];
		else
			for (int i = 1; i < mon1; i++)
				days1 += ping[i];
		days1 += day1;

		for (int i = 999; i < year2; i++)
			if (isRun(i))
				days2 += 366;
			else
				days2 += 365;
		if (isRun(year2))
			for (int i = 1; i < mon2; i++)
				days2 += run[i];
		else
			for (int i = 1; i < mon2; i++)
				days2 += ping[i];
		days2 += day2;
	
		cout << abs(days1 - days2)+1 << endl;
	}
	return 0;
}