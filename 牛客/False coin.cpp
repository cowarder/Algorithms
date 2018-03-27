#include<iostream>
#include<set>
#include<vector>
using namespace std;


/*
		 总体思路:
		 A组硬币<B组硬币时，A组全部小于等于标准重量，B组全部大于等于标准重量，其余元素全部等于标准重量
		 A组硬币>B组硬币时，A组全部大于等于标准重量，B组全部小于等于标准重量，其余元素全部等于标准重量
		 当A组硬币=B组硬币时，全部等于标准重量
		 另一种情况是，当硬币大于且等于标准重量的时候，硬币等于标准重量
		 初始为2，小于标准重量-1，等于0，大于1
*/

vector<int>v;

int main() {
	int n, k;
	while (cin >> n >> k) {
		v.clear();
		v.resize(0);
		v.resize(n + 1);
		for (int i = 1; i <= n; i++)
			v[i] = 2;
		for (int i = 1; i <= k; i++) {
			int num;
			cin >> num;
			int coin;
			set<int>set1,set2;
			for (int i = 1; i <= num; i++) {
				cin >> coin;
				set1.insert(coin);
			}
			for (int i = 1; i <= num; i++) {
				cin >> coin;
				set2.insert(coin);
			}
			char c;
			cin >> c;
			if (c == '=') {
				for (int x:set1)
					v[x] = 0;
				for (int x : set2)
					v[x] = 0;
					
			} else if (c == '>') {
				for (int x : set1) {
					if (v[x] == 0)continue;
					if (v[x] == -1)
						v[x] = 0;
					else
						v[x] = 1;
				}
				for (int x : set2) {
					if (v[x] == 0)continue;
					if (v[x] == 1)
						v[x] = 0;
					else
						v[x] = -1;
				}
				for (int i = 1; i <= n; i++)
					if (set1.find(i) == set1.end() && set2.find(i) == set2.end())
						v[i] = 0;
					
			} else if (c == '<') {
				for (int x : set1) {
					if (v[x] == 0)continue;
					if (v[x] == 1)
						v[x] = 0;
					else
						v[x] = -1;
				}
				for (int x : set2) {
					if (v[x] == 0)continue;
					if (v[x] == -1)
						v[x] = 0;
					else
						v[x] = 1;
				}
				for (int i = 1; i <= n; i++)
					if (set1.find(i) == set1.end() && set2.find(i) == set2.end())
						v[i] = 0;
			}
		}
		vector<int>index;
		for (int i = 1; i <= n; i++)
			if (v[i] != 0)
				index.push_back(i);
		if (index.size() != 1)
			cout << 0 << endl;
		else
			cout << index[0] << endl;
	}

	return 0;
}
