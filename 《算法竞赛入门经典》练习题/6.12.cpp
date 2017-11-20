//利用深度优先搜索统计图中的连同的块

#include<iostream>
using namespace std;

const int m = 5;
const int n = 5;

char pic[m][n];
int label[m][n] = { 0 };

void draw(int r, int c, int num) {
	if (r < 0 || r >= m || c < 0 || c >= n)return;	//出界的情况
	if (label[r][c]>0||pic[r][c]!='@' )return;		//已经给打了标签了或者不等于@的格子
	label[r][c] = num;
	for (int i = -1; i <= 1; i++)					//遍历所有的相邻的8个元素
		for (int j = -1; j <= 1; j++)
			if (i != 0 || j != 0) 					//当i和j不都为0的时候成立，否则会陷入无限递归中无法自拔
				draw(r + i, c + j, num);
}

int main() {
	cout << "输入一个" << m << "*" << n << "的数组:" << endl;
	for (int i = 0; i != m; i++)
		cin >> pic[i];
	int num = 0;
	memset(label, 0, sizeof(label));
	for (int k = 0; k != m; k++)
		for (int l = 0; l != n; l++)
			if (label[k][l] == 0 && pic[k][l] == '@')
				draw(k, l, ++num);
	cout << num << endl;
	return 0;
}
