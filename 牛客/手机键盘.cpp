#include<iostream>
#include<string>
#include<map>
using namespace std;
int main() {
	map<char, int> pos;
	map<char, int> len;
	for (int i = 0; i <= 15;i++) {
		pos['a' + i] = i / 3 + 1;
		len['a' + i] = i % 3+1;
	}
	pos['p'] = 6;
	len['p'] = 1;
	pos['q'] = 6;
	len['q'] = 2;
	pos['r'] = 6;
	len['r'] = 3;
	pos['s'] = 6;
	len['s'] = 4;
	pos['t'] = 7;
	len['t'] = 1;
	pos['u'] = 7;
	len['u'] = 2;
	pos['v'] = 7;
	len['v'] = 3;
	pos['w'] = 8;
	len['w'] = 1;
	pos['x'] = 8;
	len['x'] = 2;
	pos['y'] = 8;
	len['y'] = 3;
	pos['z'] = 8;
	len['z'] = 4;
	string s;
	int prepos ;
	int sum ;
	while (cin >> s) {
		prepos = 0;
		sum = 0;
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			if (prepos == pos[c])
				sum += 2;
			prepos = pos[c];
			sum += len[c];
		}
		cout << sum << endl;
	}
	return 0;
}