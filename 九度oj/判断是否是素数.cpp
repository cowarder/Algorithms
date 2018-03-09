#include<iostream>
#include<cmath>
using namespace std;

bool judge(int num) {
	if (num <= 1)
		return false;
	int bound = sqrt(num) + 1;
	for (int i = 2; i < bound; i++)
		if (num%bound == 0)
			return false;
	return true;
}

int main() {
	cout<<judge(2);
	return 0;
}