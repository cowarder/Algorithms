//6.5

#include<iostream>
#include<vector>
using namespace std;

class Link {
public:
	int index;
	int left;
	int right;
};

void Disp(vector<Link> t) {
	int temp;
	for (int i = 1; i != t.size(); i++) {
		if (t[i].left == -1) {
			temp = i;
			break;
		}
	}
	cout << t[temp].index << " ";
	int index = t[temp].right;
	while (t[index].right != -1) {
		cout << t[index].index << " ";
		index = t[index].right;
	}
	cout << t[index].index<<endl;

}

int main() {
	vector<vector<int>>instruction;		//存储指令的数组
	int n;								//盒子数目
	int insNum;							//指令条数
	cin >> n >> insNum;
	instruction.resize(insNum);
	for (int i = 0; i != insNum; i++)
		instruction[i].resize(3);
	for (int j = 0; j != insNum; j++)
		cin >> instruction[j][0] >> instruction[j][1] >> instruction[j][2];

	vector<Link> result;
	result.resize(n + 1);
	cout << endl;
	for (int k = 1; k != n + 1; k++) {
		if (k == 1) {
			result[k].left = -1;
			result[k].right = 2;
			result[k].index = k;
		}
		else if (k == n) {
			result[k].left = n - 1;
			result[k].right = -1;
			result[k].index = k;
		}
		else {
			result[k].left = k - 1;
			result[k].right = k + 1;
			result[k].index = k;
		}
	}
	result[0].index = 1;						//用于保存起始的位置
	for (int m = 0; m != insNum; m++) {
		if (instruction[m][0] == 1) {
			int index1 = instruction[m][1];
			int index2 = instruction[m][2];
			if (result[index1].left == -1) {
				result[result[index1].right].left = -1;
				result[result[index2].left].right = index1;
				result[index1].left = result[index2].left;
				result[index1].right = index2;
				result[index2].left = index1;
			}
			else {
				result[result[index1].left].right = result[index1].right;
				result[result[index1].right].left = result[index1].left;
				result[index1].left = result[index2].left;
				result[index1].right = index2;
				result[result[index2].left].right = index1;
				result[index2].left = index1;
			}
		}
		else if (instruction[m][0] == 2) {
			int index1 = instruction[m][1];
			int index2 = instruction[m][2];
			if (result[index1].left == -1) {
				result[result[index1].right].left = -1;
				if (result[index2].right == -1) {
					result[index2].right = index1;
					result[index1].left = index2;
					result[index1].right = -1;
				}
				else {
					result[index1].right = result[index2].right;
					result[index1].left = index2;
					result[result[index2].right].left = index1;
					result[index2].right = index1;
				}
			}
			else {
				result[result[instruction[m][1]].left].right = result[index1].right;
				result[result[instruction[m][1]].right].left = result[index1].left;
				if (result[index2].right == -1) {
					result[index2].right = index1;
					result[index1].left = index2;
					result[index1].right = -1;
				}
				else {
					result[index1].right = result[index2].right;
					result[index1].left = index2;
					result[result[index2].right].left = index1;
					result[index2].right = index1;
				}
			}
		}
		else if (instruction[m][0] == 3) {
			int index1 = instruction[m][1];
			int index2 = instruction[m][2];
			result[index1].index = index2;
			result[index2].index = index1;
		}
		else if (instruction[m][0] == 4) {
			for (int i = 1; i != n+1; i++) {
				if (result[i].left == -1) {
					result[i].left = result[i].right;
					result[i].right = -1;
				}
				else if (result[i].right == -1) {
					result[i].right = result[i].left;
					result[i].left = -1;
				}
				else {
					int t = result[i].left;
					result[i].left = result[i].right;
					result[i].right = t;
				}
			}
		}
		Disp(result);
	}
	return 0;
}
