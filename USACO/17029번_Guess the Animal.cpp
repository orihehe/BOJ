/*
BOJ 17029 - Guess the Animal
https://www.acmicpc.net/problem/17029

가장 공통된 특성이 많은 것 + 1
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
using namespace std;

/* 🐣🐥 */
set<string> sss[101];
int cnt[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, c, ans = 0;
	cin >> n;
	string am, cha;
	for (int i = 0; i < n; i++) {
		cin >> am >> c;
		while (c--) {
			cin >> cha;
			sss[i].insert(cha);
		}
	}
	for (int i = 0; i < n; i++) {
		memset(cnt, 0, sizeof(cnt));
		for (auto iter = sss[i].begin(); iter != sss[i].end(); iter++) {
			for (int j = i + 1; j < n; j++) {
				if (sss[j].find(*iter) != sss[j].end()) {
					cnt[j]++;
					ans = max(cnt[j], ans);
				}
			}
		}
	}
	printf("%d", ans + 1);

	return 0;
}