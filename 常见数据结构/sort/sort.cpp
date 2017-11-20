//sort.cpp
#include<iostream>
#include"sort.h"
using namespace std;

/*
	总结各类排序算法，尽量将每种算法理解透彻
*/

Sort::Sort(vector<int>nums) {
	if (nums.size() == 0) {
		cout << "初始化数组为空" << endl;
		return;
	}
	for (int x : nums)
		sortVector.push_back(x);
}

//插入循环
void Sort::insertSorting() {
	/*
		嵌套循环的每一步都需要n步，因此
		插入排序的时间复杂度为O(n²)
	*/
	if (sortVector.size() <= 1)
		return;
	for (int i = 1; i != sortVector.size(); i++) {
		for (int j = i; j > 0; j--) {
			if (sortVector[j - 1] > sortVector[j]) {
				int temp = sortVector[j];
				sortVector[j] = sortVector[j - 1];
				sortVector[j - 1] = temp;
			}
			else
				break;
		}
	}
}

//希尔排序
void Sort::shellSorting() {
	/*
		希尔排序的特点在于选择增量，假设选择的增量为k，此排序
		算法实质上是对k个子数组进行插入排序，希尔排序无法准确
		描述其性能，这里没有一种准确的选择增量模式的最优方法
	*/
	int k = 1;
	while (k < sortVector.size() / 3)k = 3 * k + 1;	//选择方法不唯一
	while (k >= 1) {
		for (int i = k; i != sortVector.size(); i++) {
			for (int j = i; j >= k&&sortVector[j - k] > sortVector[j]; j -= k) {
				int temp = sortVector[j];
				sortVector[j] = sortVector[j - k];
				sortVector[j - k] = temp;
			}
		}
		k /= 3;
	}
}

void Sort::merge(int lo, int mid, int hi) {
	int i = lo, j = mid + 1;
	vector<int> a(sortVector.begin(),sortVector.end());
	for (int k = lo; k <= hi; k++) {
		if (i > mid)
			sortVector[k] = a[j++];
		else if (j > hi)
			sortVector[k] = a[i++];
		else if (a[i] > a[j])
			sortVector[k] = a[j++];
		else
			sortVector[k] = a[i++];
	}
}

//归并排序
void Sort::mergeSorting(int lo,int hi) {
	if (hi <= lo)return;
	int mid = lo + (hi - lo) / 2;
	mergeSorting(lo, mid);		//左边排序
	mergeSorting(mid + 1, hi);	//右边排序
	merge(lo, mid, hi);			//归并
}

void Sort::displayResult() {
	for (int x : sortVector)
		cout << x  << endl;
}

