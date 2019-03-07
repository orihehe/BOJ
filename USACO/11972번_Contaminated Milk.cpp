/*
BOJ 11972 - Contaminated Milk
https://www.acmicpc.net/problem/11972

가능성이 있는 우유를 모두 찾아 최댓값을 세준다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
vector<pii> vec[51];
bool cnt[51][51]; // i사람이 j우유 마신것 체크
bool su[51], pp[51]; // su는 가능성 있는 우유
int main() {
	int n, m, mm, d, s, p, t, ans = 0;
	scanf("%d %d %d %d", &n, &mm, &d, &s);
	while (d--) {
		scanf("%d %d %d", &p, &m, &t);
		vec[p].push_back({ t,m });
		cnt[p][m] = true;
	}
	for (int i = 1; i <= n; i++) sort(vec[i].begin(), vec[i].end());
	memset(su, true, sizeof(su));
	while (s--) {
		scanf("%d %d", &p, &t);
		memset(pp, false, sizeof(pp));
		for (pii v : vec[p]) {
			if (v.first >= t) break;
			pp[v.second] = true;
		}
		// pp가 꺼져있으면 su[i]는 가능성 없음
		for (int i = 1; i <= mm; i++) {
			if (su[i] && !pp[i]) su[i] = false;
		}
	}
	for (int i = 1; i <= mm; i++) {
		int tt = 0;
		if (su[i]) {
			for (int j = 1; j <= n; j++) {
				if (cnt[j][i]) tt++;
			}
			ans = max(ans, tt);
		}
	}
	printf("%d", ans);

	return 0;
}