/*
BOJ 8012 - 한동이는 영업사원!
https://www.acmicpc.net/problem/8012
*/
#include <cstdio>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> vec[30001];
int sps[30001][15], dep[30001];
void dfs(int cur, int dd) {
	dep[cur] = dd;
	for (int i = 1; i < 15; i++)
		sps[cur][i] = sps[sps[cur][i - 1]][i - 1];
	for (int v : vec[cur]) {
		if (!dep[v]) {
			sps[v][0] = cur;
			dfs(v, dd + 1);
		}
	}
}
int lca(int a, int b) {
	if (dep[a] > dep[b]) swap(a, b);
	for (int i = 14; i >= 0; i--) {
		if (dep[sps[b][i]] >= dep[a])
			b = sps[b][i];
	}
	if (a == b) return a;
	for (int i = 14; i >= 0; i--) {
		if (sps[b][i] != sps[a][i]) {
			a = sps[a][i];
			b = sps[b][i];
		}
	}
	return sps[a][0];
}
int main() {
	int n, a, b, m, last = 1, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1, 1);
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &a);
		int lc = lca(a, last);
		ans += dep[last] + dep[a] - dep[lc] * 2;
		last = a;
	}
	printf("%d", ans);

	return 0;
}