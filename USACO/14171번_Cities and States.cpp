/*
BOJ 14171 - Cities and States
https://www.acmicpc.net/problem/14171
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

/* 🐣🐥 */
map<string, int> mp;
map<pair<string, string>, int> mmp;
string con, cd, tmp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> con >> cd;
		tmp = "";
		tmp += con[0];
		tmp += con[1];
		if (tmp == cd) continue;
		ans += mmp[{tmp, cd}];
		mmp[{cd, tmp}]++;
	}
	cout << ans;

	return 0;
}