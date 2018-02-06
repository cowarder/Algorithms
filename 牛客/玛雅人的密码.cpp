#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<utility>
using namespace std;
int n;

/*
	利用广度优先搜索算法遍历所有的字符串可能的排列
	这里记录访问过的字符串是为了减少运行时间，大约
	节约3/4的时间，并且减少了大量的内存消耗（7000-400）
	之间的差距
*/

bool isSub(string s) {
	if (s.find("2012")!=-1)
		return true;
	else
		return false;
}

int bfs(string s) {
	map<string, bool> visited;
	queue<pair<string,int>> q;
	q.push(make_pair(s, 0));
	while (!q.empty()) {
		pair<string, int>pre = q.front();
		q.pop();
		string preStr = pre.first;
		if (isSub(preStr))
			return pre.second;
		if (visited[preStr])continue;
		visited[preStr] = true;
		for (int i = 0; i < n - 1; i++) {
			swap(preStr[i], preStr[i + 1]);
			q.push(make_pair(preStr, pre.second + 1));
			swap(preStr[i], preStr[i + 1]);
		}
	}
	return -1;
}

int main() {
	string s;
	while (cin >>n>> s)
		cout << bfs(s) << endl;
	return 0;
}