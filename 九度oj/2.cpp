#include<iostream>
#include<algorithm>
#include<string>
#pragma warning(disable:4996)
using namespace std;
class stu{
public:
	int grade;
	int age;
	string name;
	bool operator<(const stu& b)const {
		if (grade != b.grade)return grade < b.grade;
		if (name.compare(b.name) == 0)
			grade < b.grade;
		else
			return name < b.name;
	}
};

bool cmp(const stu &a, const stu &b) {
	if (a.grade != b.grade)return a.grade < b.grade;
	if (a.name.compare(b.name) == 0)
		a.grade < b.grade;
	else
		return a.name < b.name;
}

stu result[1000];
int main() {
	int N;
	while (cin>>N) {
		for (int i = 0; i != N; i++) {
			cin >> result[i].name;
			cin >> result[i].age;
			cin >> result[i].grade;
		}
		sort(result, result + N);	//第一种方法，利用的是重载运算符
		//sort(result, result + N,cmp);	//第二种方法，利用的是cmp函数
		for (int i = 0; i != N; i++)
			cout << result[i].name << " " << result[i].age << " " << result[i].grade << endl;
	}
	return 0;
}