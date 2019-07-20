/*
BOJ 13511 - 트리와 쿼리 2
https://www.acmicpc.net/problem/13511
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
vector<pii> vec[100001];
int sps[100001][18], dep[100001];
ll dist[100001];
void dfs(int cur, int cnt, ll sum) {
	dep[cur] = cnt;
	dist[cur] = sum;
	for (int i = 1; i < 18; i++) {
		sps[cur][i] = sps[sps[cur][i - 1]][i - 1];
	}
	for (pii v : vec[cur]) {
		if (!dep[v.second]) {
			sps[v.second][0] = cur;
			dfs(v.second, cnt + 1, sum + v.first);
		}
	}
}
int lca(int a, int b) {
	if (dep[a] > dep[b]) swap(a, b);
	for (int i = 17; i >= 0; i--) {
		if (dep[sps[b][i]] >= dep[a]) {
			b = sps[b][i];
		}
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
	int n, a, b, c, q, d;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back({ c,b });
		vec[b].push_back({ c,a });
	}
	dfs(1, 1, 0);
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d %d", &a, &b, &c);
		int lc = lca(b, c);
		if (a == 1) {
			printf("%lld\n", dist[b] + dist[c] - 2 * dist[lc]);
		}
		else if (a == 2) {
			scanf("%d", &d);
			if (dep[b] - dep[lc] + 1 == d) {
				printf("%d\n", lc);
				continue;
			}
			if (dep[b] - dep[lc] >= d) {
				d--;
			}
			else {
				d -= dep[b] - dep[lc] + 1;
				d = dep[c] - dep[lc] - d;
				b = c;
			}

			for (int i = 17; i >= 0; i--) {
				int tt = 1 << i;
				if (d & tt) {
					b = sps[b][i];
				}
			}
			printf("%d\n", b);
		}
	}

	return 0;
}