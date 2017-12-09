#include<iostream>
#include<map>
using namespace std;

bool isRun(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}

map<int, int>runmonth = {
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
map<int, int>normmonth = {
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

int main() {
	int date1;
	int date2;
	int year1,month1,day1;
	int year2,month2,day2;
	while (cin >> date1>>date2) {
		if (date1 > date2)
			swap(date1, date2);
		year1 = date1 / 10000;
		day1 = date1 % 100;
		month1 = date2 % 10000 / 100;
		year2 = date2 / 10000;
		day2 = date2 % 100;
		month2 = date2 % 10000 / 100;
		long days=0;
		for (int y = year1 + 1; y < year2; y++) 
			if (isRun(y))
				days += 366;
			else
				days += 365;
		if (year1 == year2) {
			if (isRun(year1)) {
				for (int mon = month1 + 1; mon < month2; mon++)
					days += runmonth[mon];
				if (month1 != month2) {
					days += runmonth[month1] - day1 + 1;
					days += day2;
				} else
					days += day2 - day1 + 1;
			}
			else {
				for (int mon = month1 + 1; mon < month2; mon++)
					days += normmonth[mon];
				if (month1 != month2) {
					days += normmonth[month1] - day1 + 1;
					days += day2;
				} else
					days += day2 - day1 + 1;
			}
		}
		else {
			if (isRun(year1)) {
				for (int mon = month1+1; mon <= 12; mon++)
					days += runmonth[mon];
				days += runmonth[month1] - day1 + 1;
			}
			else{
				for (int mon = month1 + 1; mon <= 12; mon++)
					days += normmonth[mon];
				days += normmonth[month1] - day1 + 1;
			}

			if (isRun(year2)) {
				for (int mon = 1; mon <month2; mon++) 
					days += runmonth[mon];
				days += day2;
			} else {
				for (int mon = 1; mon <month2; mon++) 
					days += normmonth[mon];
				days += day2;
			}
		}
		cout << year1 << " " << month1 << " " << day1 << endl;
		cout << year2 << " " << month2 << " " << day2 << endl;
		cout << days << endl;
	}
	return 0;
}