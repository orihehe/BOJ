/*
BOJ 17264 - I AM IRONMAN
https://www.acmicpc.net/problem/17264
*/
#include <iostream>
#include <string>
#include <set>
using namespace std;

/* 🐣🐥 */
set<string> sss;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, w, l, g, ans = 0;
	char ww;
	string name;
	cin >> n >> m;
	cin >> w >> l >> g;
	for (int i = 0; i < m; i++) {
		cin >> name >> ww;
		if (ww == 'W') sss.insert(name);
	}
	while (n--) {
		cin >> name;
		if (sss.find(name) != sss.end()) {
			ans += w;
		}
		else {
			ans -= l;
			ans = ans < 0 ? 0 : ans;
		}
		if (ans >= g) {
			cout << "I AM NOT IRONMAN!!";
			return 0;
		}
	}

	cout << "I AM IRONMAN!!";

	return 0;
}