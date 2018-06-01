#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Person {
public:
	string no;
	string name;
	int grade;
};

vector<Person>v;

bool cmp1(Person& a, Person& b) {
	return a.no < b.no;
}

bool cmp2(Person& a, Person& b) {
	if (a.name != b.name)
		return a.name <= b.name;
	else
		return a.no < b.no;
}

bool cmp3(Person& a,Person& b) {
	if (a.grade != b.grade)
		return a.grade <= b.grade;
	else
		return a.no < b.no;
}

int main() {
	int n, c;
	while (cin >> n) {
		if (n == 0)
			break;
		cin >> c;
		v.clear();
		v.resize(0);
		v.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].no >> v[i].name >> v[i].grade;
		if (c == 1)
			sort(v.begin(), v.end(), cmp1);
		else if (c == 2)
			sort(v.begin(), v.end(), cmp2);
		else
			sort(v.begin(), v.end(), cmp3);
		cout << "Case:" << endl;
		for (int i = 0; i < n; i++)
			cout << v[i].no << " " << v[i].name << " " << v[i].grade << endl;

	}
	return 0;
}