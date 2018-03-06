#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class stu {
public:
	int sno;
	int grade;
};

bool comp(stu a, stu b) {
	if (a.grade != b.grade)
		return a.grade < b.grade;
	else
		return a.sno < b.sno;
}

int main() {
	int N;
	vector<stu> v;
	while (cin >> N) {
		v.resize(N);
		for (int i = 0; i < N; i++)
			cin >> v[i].sno >> v[i].grade;
		sort(v.begin(), v.end(), comp);
		for (stu s : v)
			cout << s.sno << " " << s.grade << endl;
	}
	return 0;
}