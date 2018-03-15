#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Vertex {
public:
	bool known;
	int pre;
	int dis;
	vector<int>next;
	Vertex() {
		known = false;
		pre = -1;
		dis = INT_MAX;
		next.clear();
		next.resize(0);
	}
};

vector<vector<int>>E;
vector<Vertex>V;

int main() {
	int N, M;
	while (cin >> N >> M) {
		if (N == 0 && M == 0)
			break;
		E.resize(N + 1);
		for (int i = 0; i <= N; i++)
			E[i].resize(N + 1);
		V.resize(N + 1);
		int x, y, dis;
		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= N; j++)
				E[i][j] = -1;
		for (int i = 0; i<M; i++) {
			cin >> x >> y >> dis;
			E[x][y] = E[y][x] = dis;
			V[x].next.push_back(y);
			V[y].next.push_back(x);
		}
		V[1].known = true;
		V[1].dis = 0;
		V[1].pre = 0;
		for (int i : V[1].next) {
			V[i].pre = 1;
			V[i].dis = E[1][i];
		}
		while (true) {
			int mindis = INT_MAX;
			int index = -1;
			for (int i = 1; i <= N; i++)
				if (V[i].known == false && V[i].dis <= mindis) {
					index = i;
					mindis = V[i].dis;
				}
			if (index == -1)
				break;
			V[index].known = true;
			for (int i : V[index].next) {
				if (V[i].dis > (V[index].dis + E[index][i])) {
					V[i].dis = V[index].dis + E[index][i];
					V[i].pre = index;
				}
			}
		}
		cout << V[N].dis << endl;
	}
	return 0;
}
