//6.10
//按照先序顺序递归地输入一棵树，输出在同一垂直线上面的结点值和

#include<iostream>
using namespace std;

const int maxN = 12;
int s[maxN];

//输入并统计一棵子树，p表示的是根树的水平位置
void build(int p) {
	int v;
	cin >> v;
	if (v == -1)return;
	s[p] += v;
	build(p - 1);
	build(p + 1);
}

bool init() {
	int v;
	cin >> v;
	if (v == -1)return false;
	memset(s, 0,sizeof(s));				//给内存空间进行赋值
	int pos = maxN / 2;					//数根的水平位置
	s[pos] = v;
	build(pos - 1);
	build(pos + 1);
	return true;
}

int main() {
	int kase = 0;
	while (init()) {
		int p = 0;
		while (s[p] == 0)p++;
		while (s[p] != 0)cout << " "<<s[p++];
	}
	return 0;
}