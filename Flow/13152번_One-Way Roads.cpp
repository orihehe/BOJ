/*
BOJ 13152 - One-Way Roads
https://www.acmicpc.net/problem/13152

간선을 한 정점으로 생각하여 풀어준다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define INF 1987654321
using namespace std;

/* 🐣🐥 */
const int S = 3002, E = 3003;
struct dinic {
	struct edge {
		int v, op, c, f;
	};
	vector<edge> vec[E + 1];
	int lv[E + 1], lst[E + 1];
	void addEdge(int a, int b, int f) {
		vec[a].push_back({ b,(int)vec[b].size(),f, 0 });
		vec[b].push_back({ a,(int)vec[a].size() - 1, 0, 0 });
	}
	void init(int n, int m, int mid) {
		for (int i = 0; i < n; i++)
			vec[i + m].back().c = mid;
		for (int i = 0; i <= E; i++)
			for (edge &i : vec[i]) i.f = 0;
	}
	bool bfs() {
		memset(lv, -1, sizeof(lv));
		lv[S] = 0;
		queue<int> q;
		q.push(S);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (edge &i : vec[cur]) {
				if (lv[i.v] == -1 && i.c - i.f > 0) {
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
			if (lv[i.v] == lv[cur] + 1 && i.c - i.f > 0) {
				int df = dfs(i.v, min(flow, i.c - i.f));
				if (df) {
					i.f += df;
					vec[i.v][i.op].f -= df;
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
int main() {
	int n, m, a, b, l, r, mid;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		a--, b--;
		mf.addEdge(i, a + m, 1);
		mf.addEdge(i, b + m, 1);
		mf.addEdge(S, i, 1);
	}
	for (int i = 0; i < n; i++) {
		mf.addEdge(i + m, E, 0);
	}
	l = 0, r = n;
	int ans;
	while (l <= r) {
		mid = (l + r) / 2;
		mf.init(n, m, mid);
		if (mf.getAns() >= m) {
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	printf("%d", ans);

	return 0;
}