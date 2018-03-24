#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Node {
public:
	int dis;
	bool known;
	bool through;
	int x;
	int y;
	int cost;
	char mark;
	Node() {
		cost = 1;
		dis = -1;
		known = false;
		through = true;
	}

	bool operator<(const Node& n) const{
		return dis > n.dis;
	}
};

vector<vector<Node>>v;

int main() {
	int M, N;
	while (cin >> M >> N) {
		if (M == 0 && N == 0)break;
		string s;
		v.clear();
		v.resize(0);
		v.resize(M);
		int tx, ty, sx, sy;
		for (int i = 0; i < M; i++)
			v[i].resize(N);
		for (int i = 0; i < M; i++) {
			cin >> s;
			for (int j = 0; j < N; j++) {
				v[i][j].mark = s[j];
				v[i][j].x = i;
				v[i][j].y = j;
				if (v[i][j].mark == 'S' || v[i][j].mark == 'R')
					v[i][j].through = false;
				else if (v[i][j].mark == 'Y') {
					sx = i;
					sy = j;
				} else if (v[i][j].mark == 'T') {
					tx = i;
					ty = j;
				} else if (v[i][j].mark == 'B')
					v[i][j].cost = 2;
			}
		}
		
		v[sx][sy].known = true;
		v[sx][sy].dis = 0;
		priority_queue<Node>q;
		q.push(v[sx][sy]);
		while (!q.empty()) {
			Node n = q.top();
			q.pop();
			for (int i = -1; i <= 1; i += 2) {
				if ((n.x + i )>= 0 && (n.x + i) < M)
					if (v[n.x + i][n.y].known == false && v[n.x + i][n.y].through == true) {
						v[n.x + i][n.y].known = true;
						v[n.x + i][n.y].dis = v[n.x][n.y].dis + v[n.x + i][n.y].cost;
						q.push(v[n.x + i][n.y]);
						//cout << n.x + i << " "<<n.y <<" "<< v[n.x + i][n.y].dis <<endl;
					}
				if((n.y+i)>=0&&(n.y+i)<N)
					if (v[n.x][n.y+i].known == false && v[n.x][n.y+i].through == true) {
						v[n.x][n.y+i].known = true;
						v[n.x][n.y+i].dis = v[n.x][n.y].dis + v[n.x][n.y+i].cost;
						//cout << n.x << " " << n.y+i <<" "<< v[n.x][n.y + i].dis<< endl;
						q.push(v[n.x][n.y+i]);
					}
			}
		}
		cout << v[tx][ty].dis << endl;
	}
	return 0;
}