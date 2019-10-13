/*
BOJ 15285 - Connections
https://www.acmicpc.net/problem/15285
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
vector<pii> edg[100001][2], vec;
bool chk[100001], visited[100001];
void dfs(int cur, int w) {
	visited[cur] = true;
	for (pii v : edg[cur][w]) {
		if (!visited[v.first]) {
			chk[v.second] = true;
			dfs(v.first, w);
		}
	}
}
int main() {
	int t, n, m, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		fill(chk, chk + m, false);
		fill(visited, visited + n, false);
		vec.clear();
		for (int i = 0; i < n; i++)
			edg[i][0].clear(), edg[i][1].clear();
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			vec.push_back({ a, b });
			a--, b--;
			edg[a][0].push_back({ b,i });
			edg[b][1].push_back({ a,i });
		}

		dfs(0, 0);
		fill(visited, visited + n, false);
		dfs(0, 1);

		int cnt = m - 2 * n;
		for (int i = 0; i < m; i++) {
			if (!chk[i] && cnt) {
				printf("%d %d\n", vec[i].first, vec[i].second);
				cnt--;
			}
		}
	}

	return 0;
}