#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//思路是做两次dijkstra，分别算出1和2到所有各自阵营的最短距离，然后遍历边，选出跨越两个阵营的边
//最后选择最短的距离

class Node {
public:
	int pre;
	int dis;
	bool known;
	int country;
	vector<int>next;
	Node() {
		pre = 0;
		dis =INT_MAX;
		country = 0;
		known = false;
		next.resize(0);
	}
};

vector<vector<int>>edge;
int min(int a, int b) { return a < b ? a : b; }

int main() {
	int M, N, A, B, T;
	while (cin >> N) {
		if (N == 0)
			break;
		edge.resize(N + 1);
		for (int i = 0; i <= N; i++)
			edge[i].resize(N + 1);
		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= N; j++)
				edge[i][j] = -1;
		vector<Node>v;
		v.resize(N + 1);
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> A >> B >> T;
			edge[A][B] = edge[B][A] = T;
			v[A].next.push_back(B);
			v[B].next.push_back(A);
		}
		for (int i = 1; i <= N; i++)
			cin >> v[i].country;

		v[1].known = true;
		v[1].dis = 0;
		v[1].pre = 0;
		for (int i : v[1].next) {
			if (v[i].country == 1) {
				v[i].pre = 1;
				v[i].dis = edge[1][i];
			}
		}
		while (true) {
			int index = -1;
			int min = INT_MAX;
			//找一个未知且距离最小的点
			for (int i = 1; i <= N; i++) {
				if(v[i].known==false&&v[i].country==1)
					if (v[i].dis < min) {
						index = i;
						min = v[i].dis;
					}
			}
			if (index == -1)
				break;
			v[index].known = true;
			for (int i : v[index].next) {
				if (v[i].country == 1 && (v[index].dis + edge[index][i]) < v[i].dis) {
					v[i].dis = v[index].dis + edge[index][i];
					v[i].pre = index;
				}
			}
		}

		v[2].known = true;
		v[2].dis = 0;
		v[2].pre = 0;
		for (int i : v[2].next) {
			if (v[i].country == 2) {
				v[i].dis = edge[2][i];
				v[i].pre = 2;
			}
		}
		while (true) {
			int index = -1;
			int min = INT_MAX;
			//找一个未知且距离最小的点
			for (int i = 1; i <= N; i++) {
				if (v[i].known == false && v[i].country == 2)
					if (v[i].dis < min) {
						index = i;
						min = v[i].dis;
					}
			}
			if (index == -1)
				break;
			v[index].known = true;
			for (int i : v[index].next) {
				if (v[i].country == 2 && (v[index].dis + edge[index][i]) < v[i].dis) {
					v[i].dis = v[index].dis + edge[index][i];
					v[i].pre = index;
				}
			}
		}

		int minnum = INT_MAX;
		for(int i=1;i<=N;i++)
			for (int j = i + 1; j <= N; j++) {
				if (edge[i][j] != -1) {
					if ((v[i].known == true) && (v[j].known == true) && ((v[i].country == 1 && v[j].country == 2) || (v[i].country == 2 && v[j].country == 1))) {
						minnum = min(minnum, v[i].dis + v[j].dis + edge[i][j]);
						//cout << v[j].known <<" "<<(v[j].known==true)<< endl;
						//cout <<v[i].known<<" "<< v[i].dis <<" "<<v[j].known<<" "<<v[j].dis<<endl;
					}
				}
			}
		if (minnum == INT_MAX)
			cout << -1 << endl;
		else
			cout << minnum << endl;
	}
	return 0;
}