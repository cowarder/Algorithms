#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Vertex {
public:
	int inDegree;
	vector<int>next;
	Vertex() {
		inDegree = 0;
		next.clear();
		next.resize(0);
	}
};

vector<Vertex>V;


int main() {
	int N, M;
	while (cin >> N >> M) {
		V.clear();
		V.resize(0);
		V.resize(N);
		int m, p;
		for (int i = 0; i < M; i++) {
			cin >> m >> p;
			V[m].next.push_back(p);
			V[p].inDegree++;
		}
		queue<int>q;
		for (int i = 0; i < N; i++)
			if (V[i].inDegree == 0)
				q.push(i);
		while (!q.empty()) {
			int index = q.front();
			for (int i : V[index].next) {
				V[i].inDegree--;
				if (V[i].inDegree == 0)
					q.push(i);
			}
			V[index].next.clear();
			V[index].next.resize(0);
			q.pop();
		}
		bool bingo = true;
		for (int i = 0; i < N; i++)
			if (V[i].inDegree != 0)
				bingo = false;
		if (bingo == false)
			cout << "NO"<<endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}