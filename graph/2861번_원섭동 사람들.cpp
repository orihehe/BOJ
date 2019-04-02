/*
BOJ 2861 - 원섭동 사람들
https://www.acmicpc.net/problem/2861

먼저 위상정렬을 통해 돈을 빌려야만 하는 사람을 체크하며 사이클만 남겨준다.
갚을 돈에서 위상정렬을 통해 받은 돈을 뺀 값의 최솟값을 사이클에서 구해주고,  -a
사이클에서 받을 돈을 다 받아도 갚지 못하면 빌려야하니 그 차이를 답에 더해준다.  -b
a+b가 답이된다.
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int deg[200001], mn[200001], dmn[200001], mx;
int n, a, b, ans = 0;
pii to[200001];
queue<int> q;
void dfs(int cur) {
	deg[cur] = 0;
	ans += max(0, to[cur].second - mn[cur]);
	mx = min(mx, max(0, to[cur].second - dmn[cur]));
	if (deg[to[cur].first]) dfs(to[cur].first);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a, &b);
		to[i] = { a,b };
		deg[a]++;
		mn[a] += b;
	}
	for (int i = 1; i <= n; i++) {
		if (!deg[i]) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (to[cur].second > mn[cur]) {
			ans += to[cur].second - mn[cur];
		}
		dmn[to[cur].first] += to[cur].second;
		deg[to[cur].first]--;
		if (!deg[to[cur].first]) q.push(to[cur].first);
	}
	for (int i = 1; i <= n; i++) {
		if (deg[i]) {
			mx = 2000000000;
			dfs(i);
			ans += mx;
		}
	}
	printf("%d", ans);

	return 0;
}