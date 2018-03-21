#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Stu {
public:
	string sno;
	string name;
	string sex;
	int age;
};

vector<Stu>v;

bool compare(Stu& a, Stu& b) {
	if (a.sno > b.sno)
		return false;
	else
		return true;
}

void binarySearch(string sno) {
	int low = 0;
	int high = v.size() - 1;
	int mid;
	while (low <= high) {
		mid = low + (high - low) / 2;
		if (v[mid].sno > sno)
			high = mid-1;
		else if (v[mid].sno < sno)
			low = mid+1;
		else
			break;
	}
	if (v[mid].sno == sno)
		cout << v[mid].sno << " " << v[mid].name << " " << v[mid].sex << " " << v[mid].age << endl;
	else
		cout << "No Answer!" << endl;
}

int main() {
	int n;
	int m;
	while (cin >> n){
		v.clear();
		v.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].sno >> v[i].name >> v[i].sex >> v[i].age;
		sort(v.begin(), v.end(), compare);
		cin >> m;
		string sno;
		for (int i = 0; i < m; i++) {
			cin >> sno;
			binarySearch(sno);
		}
	}
	return 0;
}
