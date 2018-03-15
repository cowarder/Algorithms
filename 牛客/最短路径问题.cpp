#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Vertex {
public:
	bool known;
	int pre;
	int dis;
	int price;
	vector<int>next;
	Vertex() {
		price = 0;
		known = false;
		pre = -1;
		dis = INT_MAX;
		next.clear();
		next.resize(0);
	}
};

vector<vector<int>>E;
vector<vector<int>>P;
vector<Vertex>V;

int main() {
	int N, M;
	while (cin >> N >> M) {
		if (N == 0 && M == 0)
			break;
		E.resize(N + 1);
		P.resize(N + 1);
		for (int i = 0; i <= N; i++) {
			E[i].resize(N + 1);
			P[i].resize(N + 1);
		}
		V.resize(N + 1);
		int x, y, dis, price;
		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= N; j++) {
				E[i][j] = -1;
				P[i][j] = -1;
			}
		for (int i = 0; i<M; i++) {
			cin >> x >> y >> dis >> price;
			if (E[x][y] == -1) {
				P[x][y] = P[y][x] = price;
				E[x][y] = E[y][x] = dis;
				V[x].next.push_back(y);
				V[y].next.push_back(x);
			}else if(dis < E[x][y]) {
				P[x][y] = P[y][x] = price;
				E[x][y] = E[y][x] = dis;
			} else if (dis == E[x][y]&&price<P[x][y]) {
				P[x][y] = P[y][x] = price;
			} else
				continue;
		}
		int s, t;
		cin >> s >> t;
		V[s].known = true;
		V[s].dis = 0;
		V[s].pre = 0;
		V[s].price = 0;
		for (int i : V[s].next) {
			V[i].pre = s;
			V[i].dis = E[s][i];
			V[i].price = P[s][i];
		}
		while (true) {
			int mindis = INT_MAX;
			int index = -1;
			for (int i = 1; i <= N; i++) {
				if (V[i].known == false && V[i].dis <= mindis) {
					index = i;
					mindis = V[i].dis;
				}
			}
			if (index == -1)
				break;
			V[index].known = true;
			for (int i : V[index].next) {
				if (V[i].dis > (V[index].dis + E[index][i])) {
					V[i].dis = V[index].dis + E[index][i];
					V[i].price = V[index].price + P[index][i];
					V[i].pre = index;
				} else if (V[i].dis == (V[index].dis + E[index][i]) && (V[index].price + P[index][i]) < V[i].price) {
					V[i].price = V[index].price + P[index][i];
					V[i].pre = index;
				} else
					continue;
			}
		}
		cout << V[t].dis << " " << V[t].price << endl;
	}
	return 0;
}
