#include<iostream>
#include<map>
#include<vector>
using namespace std;
/*
	直接进行find操作查找的是key
	如果是想找出查找的第一个数据或者是第二个数据
	那么可以使用m.find(1)->first或者是m.find(1)->second
*/

int main() {
	int n;
	int x;
	while (cin >> n) {
		map<int, int>m;
		int num;
		for (int i = 0; i < n; i++) {
			cin >> num;
			m[num] = i;
		}
		cin >> x;
		if (m.find(x) == m.end())
			cout << -1;
		else
			cout << m[x] << endl;
		
	}
	return 0;
}