/*
BOJ 3938 - Concert Hall Scheduling
https://www.acmicpc.net/problem/3938
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
const int S = 203, E = 204;
struct mcmf {
	struct edge {
		int v, c, op, cost;
	};
	vector<edge> eg[E + 1];
	int dist[E + 1], p[E + 1], pidx[E + 1];
	bool inq[E + 1];
	void init() {
		for (int i = 0; i <= E; i++) eg[i].clear();
	}
	void addEdge(int a, int b, int f, int cost) {
		eg[a].push_back({ b,f,(int)eg[b].size(),cost });
		eg[b].push_back({ a,0,(int)eg[a].size() - 1,-cost });
	}
	bool spfa() {
		queue<int> q;
		fill(dist, dist + E + 1, INF);
		memset(inq, false, sizeof(inq));
		memset(p, -1, sizeof(p));
		dist[S] = 0;
		inq[S] = true;
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
		while (spfa()) {
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
struct info { int s, e, val; } arr[101];
int main() {
	int n;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		mf.init();
		for (int i = 0; i < n; i++)
			scanf("%d %d %d", &arr[i].s, &arr[i].e, &arr[i].val);
		mf.addEdge(S, 202, 2, 0);
		for (int i = 0; i < n; i++) {
			mf.addEdge(i, i + n, 1, -arr[i].val);
			mf.addEdge(i + n, E, 1, 0);
			mf.addEdge(202, i, 1, 0);
			for (int j = 0; j < n; j++) {
				if (arr[i].e < arr[j].s) {
					mf.addEdge(i + n, j, 1, 0);
				}
			}
		}
		printf("%d\n", -mf.getAns().second);
	}

	return 0;
}