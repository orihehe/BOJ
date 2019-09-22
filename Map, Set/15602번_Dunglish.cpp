/*
BOJ 15602 - Dunglish
https://www.acmicpc.net/problem/15602
*/
#include <iostream>
#include <string>
#include <map>
#define ll long long
using namespace std;

/* 🐣🐥 */
int cor[21], incor[21];
string arr[21];
map<string, string> mp;
map<string, int> num;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, c = 0;
	cin >> n;
	string x, y, z;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (!num[arr[i]]) {
			num[arr[i]] = c++;
		}
	}
	bool flag = true;
	bool ccc = false;
	cin >> m;
	while (m--) {
		cin >> x >> y >> z;
		if (num.find(x) == num.end()) continue;
		int my = num[x];
		mp[x] = y;
		if (z == "correct") cor[my]++;
		else incor[my]++, ccc = true;
		if (cor[my] >= 2) flag = false;
		if (incor[my] >= 2) flag = false;
	}
	if (flag) {
		for (int i = 0; i < n; i++)
			cout << mp[arr[i]] << ' ';
		cout << '\n';
		if (ccc) cout << "incorrect";
		else cout << "correct";
	}
	else {
		ll ans = 1, oc = 1;
		for (int i = 0; i < n; i++) {
			ans *= cor[num[arr[i]]] + incor[num[arr[i]]];
			oc *= cor[num[arr[i]]];
		}
		cout << oc << " correct\n";
		cout << ans - oc << " incorrect";
	}

	return 0;
}