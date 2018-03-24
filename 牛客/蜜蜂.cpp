#include<iostream>
#include<vector>
using namespace std;

vector<long long>v;

int main() {
	int N, a, b;
	while (cin >> N) {
		for (int i = 0; i < N; i++) {
			v.clear();
			v.resize(0);
			v.resize(50);
			cin >> a >> b;
			if((b-1)>=1)
				v[a + 1] = 1;
			if((b-1)>=2)
				v[a + 2] = 2;
			for (int j = (a + 3); j <= b; j++)
				v[j] = v[j - 1] +  v[j - 2];
			cout << v[b] << endl;
		}
	}
	return 0;
}