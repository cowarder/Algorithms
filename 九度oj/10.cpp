#include<iostream>
#include<map>
using namespace std;
int main() {
	map<int, int> hash;
	int n;
	int num;
	int target;
	while (cin >> n) {
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			cin >> num;
			if (hash.find(num) == hash.end())
				hash[num] = 1;
			else
				hash[num] += 1;
		}
		cin >> target;
		if (hash.find(target) == hash.end())
			cout << 0 << endl;
		else
			cout << hash[target] << endl;
		hash.clear();
	}
	return 0;

}