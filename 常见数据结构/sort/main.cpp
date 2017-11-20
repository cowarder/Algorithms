#include"sort.h"
#include<iostream>
using namespace std;

int main() {
	vector<int>a{ 1,23,43,0,-89,-59,-2,185,39,6,-7,-56,456,789 };
	vector<int>b{};
	Sort test(a);
	test.mergeSorting(0,test.sizeOfVector()-1);
	test.displayResult();
	int c;
	cin >> c;
}
