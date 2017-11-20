#ifndef SORT_HEAD
#define SORT_HEAD

//sort.cpp
#include<vector>
using namespace std;

/*
总结各类排序算法，尽量将每种算法理解透彻
*/

class Sort {
public:
	Sort();
	Sort(vector<int>);
	void merge(int,int,int);
	void insertSorting();
	void shellSorting();
	void mergeSorting(int,int);
	int sizeOfVector() { return sortVector.size(); }
	void displayResult();
private:
	vector<int> sortVector;
};



#endif