/*
BOJ 13569 - Rounding
https://www.acmicpc.net/problem/13569
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#define INF 1987654321
using namespace std;

/* 🐣🐥 */
const int S = 406, E = 407;
struct dinic {
	struct edge {
		int v, op, c;
	};
	int lv[E + 1], lst[E + 1];
	queue<int> q;
	vector<edge> edg[E + 1];
	void addEdge(int a, int b, int f) {
		edg[a].push_back({ b,(int)edg[b].size(),f });
		edg[b].push_back({ a,(int)edg[a].size() - 1,0 });
	}
	bool bfs() {
		memset(lv, -1, sizeof(lv));
		q.push(S);
		lv[S] = 0;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (edge &i : edg[cur]) {
				if (lv[i.v] == -1 && i.c > 0) {
					lv[i.v] = lv[cur] + 1;
					q.push(i.v);
				}
			}
		}
		return lv[E] != -1;
	}
	int dfs(int cur, int flow) {
		if (cur == E) return flow;
		int sz = edg[cur].size();
		for (int &k = lst[cur]; k < sz; k++) {
			edge &i = edg[cur][k];
			if (lv[i.v] == lv[cur] + 1 && i.c > 0) {
				int df = dfs(i.v, min(flow, i.c));
				if (df) {
					i.c -= df;
					edg[i.v][i.op].c += df;
					return df;
				}
			}
		}
		return 0;
	}
	int getAns() {
		int ans = 0;
		while (bfs()) {
			memset(lst, 0, sizeof(lst));
			while (true) {
				int ret = dfs(S, INF);
				if (!ret) break;
				ans += ret;
			}
		}
		return ans;
	}
} mf;
int pls[E + 1], ans[202][202];
int main() {
	int n, m, s = S - 2, e = E - 2, x, y;
	scanf("%d %d", &n, &m);
	n++, m++;
	mf.addEdge(e, s, INF);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == n - 1 && j == m - 1) break;
			scanf("%d.%d", &x, &y);
			ans[i][j] = x;
			if (j == m - 1) {
				if (y) mf.addEdge(s, i, 1);
				pls[s] += x, pls[i] -= x;
			}
			else if (i == n - 1) {
				if (y) mf.addEdge(j + n, e, 1);
				pls[j + n] += x, pls[e] -= x;
			}
			else {
				if (y) mf.addEdge(i, j + n, 1);
				pls[i] += x, pls[j + n] -= x;
			}
		}
	}
	for (int i = 0; i <= E; i++) {
		if (pls[i] > 0) mf.addEdge(i, E, pls[i]);
		else if (pls[i] < 0)mf.addEdge(S, i, -pls[i]);
	}
	mf.getAns();
	for (int j = 0; j < m - 1; j++) {
		for (auto v : mf.edg[j + n]) {
			if (v.v == e && v.c == 0) ans[n - 1][j]++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (auto v : mf.edg[i]) {
			if (v.v < s && v.c == 0) ans[i][v.v - n]++;
			if (v.v == s && v.c == 1) ans[i][m - 1]++;
		}
		for (int j = 0; j < m; j++) {
			if (i == n - 1 && j == m - 1) break;
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}