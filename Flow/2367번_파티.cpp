/*
BOJ 2367 - 파티
https://www.acmicpc.net/problem/2367
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

/* 🐣🐥 */
struct edg {
	int v, c, f;
	edg *op;
	edg() : edg(-1, 0) {}
	edg(int a, int b) {
		v = a, c = b, f = 0, op = 0;
	}
	void add(int ff) {
		f += ff;
		op->f -= ff;
	}
};
vector<edg *> vec[320];
int lv[320], lst[320];
const int S = 310, E = 311;
void aeg(int a, int b, int c, int d) {
	edg *e1 = new edg(a, b);
	edg *e2 = new edg(c, d);
	e1->op = e2;
	e2->op = e1;
	vec[a].push_back(e2);
	vec[c].push_back(e1);
}
bool bfs() {
	memset(lv, -1, sizeof(lv));
	lv[S] = 0;
	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (edg *i : vec[cur]) {
			if (lv[i->v] == -1 && i->c - i->f > 0) {
				lv[i->v] = lv[cur] + 1;
				q.push(i->v);
			}
		}
	}
	return lv[E] != -1;
}
int dfs(int cur, int flow) {
	if (cur == E) return flow;
	int sz = vec[cur].size();
	for (int &k = lst[cur]; k < sz; k++) {
		edg *i = vec[cur][k];
		if (lv[i->v] == lv[cur] + 1 && i->c - i->f > 0) {
			int df = dfs(i->v, min(flow, i->c - i->f));
			if (df > 0) {
				i->add(df);
				return df;
			}
		}
	}
	return 0;
}
int main() {
	int n, k, d, x, z, ans = 0;
	scanf("%d %d %d", &n, &k, &d);
	for (int i = 0; i < d; i++) {
		scanf("%d", &x);
		aeg(n + i, 0, E, x);
	}
	for (int i = 0; i < n; i++) {
		aeg(S, 0, i, k);
		scanf("%d", &x);
		while (x--) {
			scanf("%d", &z);
			--z;
			aeg(i, 0, n + z, 1);
		}
	}
	while (bfs()) {
		memset(lst, 0, sizeof(lst));
		while (true) {
			int ret = dfs(S, INF);
			if (ret == 0) break;
			ans += ret;
		}
	}
	printf("%d", ans);

	return 0;
}