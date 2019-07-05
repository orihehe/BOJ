/*
BOJ 2311 - 왕복 여행
https://www.acmicpc.net/problem/2311

1->N으로의 경로 두 개를 찾는다.
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
const int S = 1002, E = 1003;
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
		fill(dist, dist + E + 1, INF);
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
			int mn = INF;
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
	int n, m, a, b, c;
	scanf("%d %d", &n, &m);
	mf.addEdge(S, 0, 2, 0);
	mf.addEdge(n - 1, E, 2, 0);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		a--, b--;
		mf.addEdge(a, b, 1, c);
		mf.addEdge(b, a, 1, c);
	}
	printf("%d", mf.getAns().second);

	return 0;
}