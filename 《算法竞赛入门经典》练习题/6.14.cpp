//利用广度优先计算节点到所有节点的最短路径


#include<iostream>
#include<queue>
using namespace std;

const int m = 5;
const int n = 5;

class Coordinate {
public:
	Coordinate() {};
	Coordinate(int s, int m) { i = s, j = m; }
	int i;
	int j;
};

class Node {
public:
	Node() { pathLength = -1; }
	Coordinate pre;			//指向当前节点前一个节点的坐标
	int pathLength;			//起始节点到当前节点的最短路径长度
	int x;
	int y;
};

int visible[m][n];
Node label[m][n];

void init() {
	for (int i = 0; i != m; i++)
		for (int j = 0; j != n; j++)
			cin >> visible[i][j];			//输入地图模型，0表示不可通，1表示可通
}

vector<Coordinate> getNearNodes(Node node) {
	vector<Coordinate>near;
	if (node.x != 0 && visible[node.x - 1][node.y] != 0)
		near.push_back(Coordinate(node.x - 1, node.y));
	if (node.x != n - 1 && visible[node.x + 1][node.y] != 0)
		near.push_back(Coordinate(node.x + 1, node.y));
	if (node.y != 0 && visible[node.x][node.y - 1] != 0)
		near.push_back(Coordinate(node.x, node.y - 1));
	if (node.y != m - 1 && visible[node.x][node.y + 1] != 0)
		near.push_back(Coordinate(node.x, node.y + 1));
	return near;
}


int main() {
	init();
	int startX;
	int startY;
	int endX;
	int endY;
	cout << "输入起始节点坐标:";
	cin >> startX >> startY;
	cout << "输入结束节点的坐标:" ;
	cin >> endX >> endY;
	queue<Node>q;
	label[startX][startY].pathLength = 0;
	label[startX][startY].x = startX;
	label[startX][startY].y = startY;
	q.push(label[startX][startY]);
	while (q.size() != 0) {
		Node s = q.front();
		vector<Coordinate>cList = getNearNodes(s);
		for (Coordinate c : cList ){			//遍历所有的邻接节点
			int i = c.i;
			int j = c.j;
			if ((label[i][j].pathLength < 0)||(s.pathLength+1<label[i][j].pathLength)) {
				label[i][j].pathLength = s.pathLength + 1;
				label[i][j].pre.i = s.x;
				label[i][j].pre.j = s.y;
				label[i][j].x = i;
				label[i][j].y = j;
				q.push(label[i][j]);				//如果发生了改变，那么之前与之相邻的结点的最短路径需要更新，所以重新加入到队列中重新更新
			}
		}
		q.pop();
	}
	cout << "The shortest length is:";
	cout << label[endX][endY].pathLength << endl;
	return 0;
}
