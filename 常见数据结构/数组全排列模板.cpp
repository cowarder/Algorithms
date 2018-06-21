#include <iostream>  
#include <vector>  
using namespace std;

void permutation(vector<int>& v, int index) {
	if (index >= v.size()) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;
		return;
	}
	for (int i = index; i < v.size(); i++) {
		swap(v[i], v[index]);
		permutation(v, index + 1);
		swap(v[index], v[i]);
	}
}

int main() {
	vector<int> v = { 1,2,3 };
	permutation(v, 0);
	return 0;
}