/*
BOJ 11493 - 동전 교환
https://www.acmicpc.net/problem/11493

검은 정점으로 검은 동전을 모두 보낸다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
const int S = 501, E = 502;
int ans = 0;
struct mcmf {
	struct edge {
		int v, c, op, cost;
	};
	int dist[E + 1], p[E + 1], pidx[E + 1];
	bool inq[E + 1];
	vector<edge> eg[E + 1];
	void init() {
		for (int i = 0; i <= E; i++) eg[i].clear();
	}
	void addEdge(int a, int b, int f, int cost) {
		eg[a].push_back({ b,f,(int)eg[b].size(),cost });
		eg[b].push_back({ a,0,(int)eg[a].size() - 1,-cost });
	}
	bool SPFA() {
		memset(inq, false, sizeof(inq));
		memset(p, -1, sizeof(p));
		fill(dist, dist + E + 1, 5000);
		queue<int> q;
		inq[S] = true;
		dist[S] = 0;
		q.push(S);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			inq[cur] = false;
			int sz = eg[cur].size();
			for (int k = 0; k < sz; k++) {
				edge i = eg[cur][k];
				if (i.c > 0 && dist[cur] + i.cost < dist[i.v]) {
					dist[i.v] = dist[cur] + i.cost;
					p[i.v] = cur;
					pidx[i.v] = k;
					if (!inq[i.v]) {
						inq[i.v] = true;
						q.push(i.v);
					}
				}
			}
		}
		return p[E] != -1;
	}
	pii getAns() {
		pii ret = { 0,0 };
		while (SPFA()) {
			int mn = 5000;
			for (int i = E; i != S; i = p[i]) {
				mn = min(mn, eg[p[i]][pidx[i]].c);
			}
			ret.first += mn;
			for (int i = E; i != S; i = p[i]) {
				ret.second += mn * eg[p[i]][pidx[i]].cost;
				eg[p[i]][pidx[i]].c -= mn;
				eg[i][eg[p[i]][pidx[i]].op].c += mn;
			}
		}
		return ret;
	}
} mf;
int main() {
	int tt, n, m, a, b, x;
	scanf("%d", &tt);
	while (tt--) {
		mf.init();
		scanf("%d %d", &n, &m);
		while (m--) {
			scanf("%d %d", &a, &b);
			mf.addEdge(a, b, 5000, 1);
			mf.addEdge(b, a, 5000, 1);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &x);
			if (x) mf.addEdge(i, E, 1, 0);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &x);
			if (x) mf.addEdge(S, i, 1, 0);
		}
		printf("%d\n", mf.getAns().second);
	}

	return 0;
}