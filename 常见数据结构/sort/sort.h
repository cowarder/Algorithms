#ifndef SORT_HEAD
#define SORT_HEAD

//sort.cpp
#include<vector>
using namespace std;

/*
�ܽ���������㷨��������ÿ���㷨���͸��
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