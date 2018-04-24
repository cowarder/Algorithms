#include<iostream>
#include<vector>
using namespace std;
char a, b;

char turn(char c) {
	if (c == a)
		return b;
	else
		return a;
}

int main() {
	int size;
	while (cin >> size >> a >> b) {
		vector<vector<char>>v;
		v.resize(size);
		for (int i = 0; i < size; i++)
			v[i].resize(size);
		char pre = b;
		for (int i = 0; i <= (size / 2); i++) {
			for (int m = i; m < (size - i); m++) {
				v[i][m] = pre;
				v[m][i] = pre;
				v[size - i - 1][m] = pre;
				v[m][size - i - 1] = pre;
			}
			pre = turn(pre);
		}
		if(size!=1){
			v[0][0] = ' ';
			v[0][size - 1] = ' ';
			v[size - 1][0] = ' ';
			v[size - 1][size - 1] = ' ';
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
				cout << v[i][j];
			cout << endl;
		}
	}
	return 0;
}