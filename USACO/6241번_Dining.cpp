/*
BOJ 6241 - Dining
https://www.acmicpc.net/problem/6241

소스 - 음식 - 소-소 - 음료 - 싱크
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

/* 🐣🐥 */
const int S = 401, E = 402;
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
int main() {
	int n, f, d, a, b, x;
	scanf("%d %d %d", &n, &f, &d);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		mf.addEdge(200 + i, 300 + i, 1);
		while (a--) {
			scanf("%d", &x);
			x--;
			mf.addEdge(x, 200 + i, 1);
		}
		while (b--) {
			scanf("%d", &x);
			x--;
			mf.addEdge(300 + i, 100 + x, 1);
		}
	}
	for (int i = 0; i < f; i++) mf.addEdge(S, i, 1);
	for (int i = 0; i < d; i++) mf.addEdge(100 + i, E, 1);
	printf("%d", mf.getAns());

	return 0;
}