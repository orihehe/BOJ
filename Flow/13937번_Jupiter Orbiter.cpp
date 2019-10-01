/*
BOJ 13937 - Jupiter Orbiter
https://www.acmicpc.net/problem/13937
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

/* 🐣🐥 */
const int S = 1832, E = 1833;
struct dinic {
	struct edge {
		int v, op, c;
	};
	int lv[E + 1], lst[E + 1];
	queue<int> q;
	vector<edge> vec[E + 1];
	void addEdge(int a, int b, int f) {
		vec[a].push_back({ b,(int)vec[b].size(),f });
		vec[b].push_back({ a,(int)vec[a].size() - 1,0 });
	}
	bool bfs() {
		memset(lv, -1, sizeof(lv));
		q.push(S);
		lv[S] = 0;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (edge &i : vec[cur]) {
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
		int sz = vec[cur].size();
		for (int &k = lst[cur]; k < sz; k++) {
			edge &i = vec[cur][k];
			if (lv[i.v] == lv[cur] + 1 && i.c > 0) {
				int df = dfs(i.v, min(flow, i.c));
				if (df) {
					i.c -= df;
					vec[i.v][i.op].c += df;
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
int Q[30], sum[30], ss[100];
int main() {
	int n, q, s, x, y, al = 0;
	int to = 0;
	scanf("%d %d %d", &n, &q, &s);
	for (int i = 0; i < s; i++) {
		scanf("%d", &ss[i]);
		ss[i]--;
	}
	for (int i = 0; i < q; i++) {
		scanf("%d", &Q[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		memset(sum, 0, sizeof(sum));
		for (int j = 0; j < s; j++) {
			scanf("%d", &y);
			to += y;
			sum[ss[j]] += y;
		}
		for (int j = 0; j < q; j++) {
			mf.addEdge(S, j + 61 * i, sum[j]);
			mf.addEdge(j + 61 * i, j + 61 * i + 30, Q[j]);
			mf.addEdge(j + 61 * i + 30, i * 61 + 60, INF);
			if (i < n - 1) {
				mf.addEdge(j + 61 * i + 30, j + 61 * (i + 1), INF);
			}
		}
		mf.addEdge(i * 61 + 60, E, x);
	}
	int ans = mf.getAns();
	if (ans == to) printf("possible");
	else printf("impossible");

	return 0;
}