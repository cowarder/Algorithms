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
	int day;
	string smon;
	int year;
	int mon;
	while (cin >> day >> smon >> year) {
		mon = getMonth[smon];
		int days;
		if (year < 2018) {
			days = 111;
			for (int y = year + 1; y < 2018; y++)
				if (isRun(y))
					days += 366;
				else
					days += 365;
			int thatdays = 0;
			if (isRun(year))
				for (int i = 1; i < mon; i++)
					thatdays += run[i];
			else
				for (int i = 1; i < mon; i++)
					thatdays += ping[i];
			thatdays += day;
			if (isRun(year))
				days += (366-thatdays);
			else
				days += (365-thatdays);
			int gap = days % 7;
			if (gap == 6)
				cout << "Sunday" << endl;
			else
				cout << week[5 - gap] << endl;
		} else if (year > 2018) {
			days = 253;
			for (int y = 2019; y < year; y++)
				if (isRun(y))
					days += 366;
				else
					days += 365;
			int thatdays = 0;
			if (isRun(year))
				for (int i = 1; i < mon; i++)
					thatdays += run[i];
			else
				for (int i = 1; i < mon; i++)
					thatdays += ping[i];
			thatdays += (day-1);
			days += thatdays;
			int gap = days % 7;
			if (gap == 0)
				cout << "Monday" << endl;
			else
				cout << week[gap] << endl;
		} else {
			if (mon < 4) {
				days = 21;
				for (int i = mon + 1; i < 4; i++)
					days += ping[i];
				days += ping[mon] - day;
				int gap = days % 7;
				if (gap == 6)
					cout << "Sunday" << endl;
				else
					cout << week[5 - gap] << endl;
			} else if (mon > 4) {
				if (mon < 4) {
					days = 8;
					for (int i = 5; i < mon; i++)
						days += ping[i];
					days += (day-1);
					int gap = days % 7;
					if (gap == 0)
						cout << "Monday" << endl;
					else
						cout << week[gap] << endl;
				}
			} else {

			}
		}
	}
	return 0;
}