/*
BOJ 17399 - 트리의 외심
https://www.acmicpc.net/problem/17399
*/
#include <cstdio>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> vec[100001];
int dep[100001], sps[100001][18];
void dfs(int cur, int cnt) {
	dep[cur] = cnt;
	for (int i = 1; i < 18; i++)
		sps[cur][i] = sps[sps[cur][i - 1]][i - 1];
	for (int v : vec[cur]) {
		if (!dep[v]) {
			sps[v][0] = cur;
			dfs(v, cnt + 1);
		}
	}
}
int lca(int a, int b) {
	if (dep[a] > dep[b]) swap(a, b);
	for (int i = 17; i >= 0; i--) {
		if (dep[sps[b][i]] >= dep[a]) b = sps[b][i];
	}
	if (a == b) return a;
	for (int i = 17; i >= 0; i--) {
		if (sps[a][i] != sps[b][i]) {
			a = sps[a][i];
			b = sps[b][i];
		}
	}
	return sps[a][0];
}
int main() {
	int n, a, b, c, q, s, e, dd, lc, r;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1, 1);
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d %d", &a, &b, &c);
		lc = lca(a, b);
		s = a, e = b, r = c;
		dd = dep[a] + dep[b] - dep[lc] * 2;
		lc = lca(a, c);
		if (dd < dep[a] + dep[c] - dep[lc] * 2) {
			dd = dep[a] + dep[c] - dep[lc] * 2;
			s = a, e = c, r = b;
		}
		lc = lca(b, c);
		if (dd < dep[b] + dep[c] - dep[lc] * 2) {
			dd = dep[b] + dep[c] - dep[lc] * 2;
			s = b, e = c, r = a;
		}
		if (dd % 2) {
			printf("-1\n");
			continue;
		}
		if (dep[s] > dep[e]) swap(s, e);
		dd /= 2;
		for (int i = 0; i < 18; i++) {
			int t = 1 << i;
			if (t&dd) e = sps[e][i];
		}
		if (dep[e] + dep[r] - dep[lca(e, r)] * 2 == dd) printf("%d\n", e);
		else printf("-1\n");
	}

	return 0;
}