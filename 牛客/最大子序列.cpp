#O(N^2)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	while (cin >> N) {
		vector<int>v;
		v.resize(N);
		for (int i = 0; i < N; i++)
			cin >> v[i];
		int max = *max_element(v.begin(),v.end());
		for (int i = 0; i < N; i++) {
			int sum = 0;
			for (int j = i; j < N; j++) {
				sum += v[j];
				if (sum > max)
					max = sum;
			}
		}
		cout << max << endl;
	}
	return 0;
}


#O(N)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	while (cin >> N) {
		vector<int>v;
		v.resize(N);
		for (int i = 0; i < N; i++)
			cin >> v[i];
		//int max = *max_element(v.begin(),v.end());
        int max =0;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += v[i];
			if (sum > max)
				max = sum;
			if (sum < 0)
				sum = 0;
		}
		cout << max << endl;
	}
	return 0;
}

