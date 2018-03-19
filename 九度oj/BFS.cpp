#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int A, B, C, T;

class N {
public:
	int x, y,z;
	bool mark;
	int len;
	N() {
		mark = false;
		len = 0;
	}
};
vector<vector<vector<N>>>v;
int BFS() {
	queue<N>q;
	q.push(v[0][0][0]);
	while (!q.empty()) {
		N n = q.front();
		int x = n.x;
		int y = n.y;
		int z = n.z;
		int len = n.len;
		q.pop();
		for (int index = -1; index <= 1; index += 2) {
			if ((x + index) >= 0 && (x + index) < A&&v[x + index][y][z].mark == false) {
				v[x + index][y][z].mark = true;
				v[x + index][y][z].len = len + 1;
				if ((x + index) == (A - 1) && y == (B - 1) && z == (C - 1))
					return len + 1;
				q.push(v[x + index][y][z]);
			}
			if((y + index) >= 0 && (y + index) < B &&v[x][y+index][z].mark==false) {
				v[x][y+index][z].mark = true;
				v[x][y+index][z].len = len + 1;
				if (x == (A - 1) && (y+index) == (B - 1) && z == (C - 1))
					return len + 1;
				q.push(v[x][y+index][z]);
			}
			if ((z + index) >= 0 && (z + index) < C&&v[x][y][z+index].mark==false) {
				v[x][y][z+index].mark = true;
				v[x][y][z+index].len = len + 1;
				if (x == (A - 1) && y == (B - 1) && (z+index) == (C - 1))
					return len + 1;
				q.push(v[x][y][z+index]);
			}
		}
	}
	return -1;
}

int main() {
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> A >> B >> C >> T;
		v.clear();
		v.resize(0);
		v.resize(A);
		for (int i = 0; i < A; i++) {
			v[i].resize(B);
			for (int j = 0; j < B; j++)
				v[i][j].resize(C);
		}
		for (int i = 0; i < A; i++)
			for (int j = 0; j < B; j++)
				for (int k = 0; k < C; k++) {
					cin >> v[i][j][k].mark;
					v[i][j][k].x = i;
					v[i][j][k].y = j;
					v[i][j][k].z = k;
				}
		int dis=BFS();
		cout << "dis:" << dis << endl;
		if (dis == -1 || dis > T)
			cout << -1 << endl;
	}
	return 0;
}