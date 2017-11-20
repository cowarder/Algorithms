//6.3

#include<iostream>
#include<string>
#include<stack>

using namespace std;
class Mat {
public:
	int x;
	int y;
};

Mat judge(Mat &a, Mat &b) {
	Mat c;
	c.x = 0;
	c.y = 0;
	if (a.y == b.x) {
		c.x = a.x;
		c.y = b.y;
	}
	return c;
}

int main() {
	cout << "输入公式：" << endl;
	string formula;
	cin >> formula;
	Mat A, B, C;
	cout << "输入各矩阵的行和列：" << endl;
	cin >> A.x >> A.y;
	cin >> B.x >> B.y;
	cin >> C.x >> C.y;
	stack<Mat> result;
	for (int i = 0; i != formula.length(); i++) {
		if (formula[i] == 'A')
			result.push(A);
		else if (formula[i] == 'B')
			result.push(B);
		else if (formula[i] == 'C')
			result.push(C);
		else if (formula[i] == ')') {
			Mat a = result.top();
			result.pop();
			Mat b = result.top();
			result.pop();
			result.push(judge(b, a));
		}
	}
	if (result.top().x == 0)
		cout << "error" << endl;
	else
		cout << result.top().x << result.top().y << endl;

	return 0;
}