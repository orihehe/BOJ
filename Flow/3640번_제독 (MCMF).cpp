/*
BOJ 3640 - 제독
https://www.acmicpc.net/problem/3640

MCMF
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define INF 987654321
using namespace std;

/* 🐣🐥 */
const int S = 2002, E = 2003;
struct mcmf {
	struct edge {
		int u, v, c, op, cost;
	};
	int dist[E + 1], p[E + 1];
	bool inq[E + 1];
	vector<edge> eg;
	vector<int> vec[E + 1];
	void init() {
		eg.clear();
		for (int i = 0; i <= E; i++) vec[i].clear();
	}
	void addEdge(int a, int b, int f, int cost) {
		int sz = eg.size();
		edge e1 = { a,b,f,sz + 1,cost };
		edge e2 = { b,a,0,sz,-cost };
		eg.push_back(e1);
		eg.push_back(e2);
		vec[a].push_back(sz);
		vec[b].push_back(sz + 1);
	}
	bool SPFA() {
		memset(inq, false, sizeof(inq));
		memset(p, -1, sizeof(p));
		fill(dist, dist + E + 1, INF);
		queue<int> q;
		inq[S] = true;
		dist[S] = 0;
		q.push(S);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			inq[cur] = false;
			for (int v : vec[cur]) {
				edge i = eg[v];
				if (i.c > 0 && dist[cur] + i.cost < dist[i.v]) {
					dist[i.v] = dist[cur] + i.cost;
					p[i.v] = v;
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
			int mn = INF;
			for (int i = E; i != S; i = eg[p[i]].u) {
				mn = min(mn, eg[p[i]].c);
			}
			ret.first += mn;
			for (int i = E; i != S; i = eg[p[i]].u) {
				ret.second += mn * eg[p[i]].cost;
				eg[p[i]].c -= mn;
				eg[eg[p[i]].op].c += mn;
			}
		}
		return ret;
	}
} mf;
int main() {
	int n, m, a, b, c;
	while (~scanf("%d %d", &n, &m)) {
		mf.init();
		mf.addEdge(S, 1, 2, 0);
		mf.addEdge(2 * n, E, 2, 0);
		for (int i = 2; i < n; i++) mf.addEdge(i, i + n, 1, 0);
		mf.addEdge(n, n + n, 2, 0);
		mf.addEdge(1, 1 + n, 2, 0);
		while (m--) {
			scanf("%d %d %d", &a, &b, &c);
			mf.addEdge(a + n, b, 1, c);
		}
		printf("%d\n", mf.getAns().second);
	}

	return 0;
}