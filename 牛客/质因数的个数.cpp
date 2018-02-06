#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int getMinPrime(int num) {
	if (num < 0)
		num = -num;
	for (int i = 2; i <= sqrt(num); i++)
		if (num%i == 0)
			return i;
	return num;
}

int main() {
	int num;
	int newPrime;
	vector<int> v;
	while (cin >> num) {
		newPrime = getMinPrime(num);
		while (newPrime!=num) {
			if (num > newPrime) {
				if (num%newPrime == 0) {
					v.push_back(newPrime);
					num = num / newPrime;
				} else {
					newPrime =getMinPrime(num);
				}
			}	
		}
		v.push_back(num);
		cout <<v.size()<< endl;
		v.clear();
	}
	return 0;
}