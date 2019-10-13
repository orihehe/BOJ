/*
BOJ 17506 - 주때의 자소서 쓰기
https://www.acmicpc.net/problem/17506

각 문항에 최소 하나의 스토리가 필요하다.
따라서 용량이 1이고 가중치가 큰 간선 하나를 문항->E에 만들어준다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define INF 1987654321
#define MAX 5000000
using namespace std;

/* 🐣🐥 */
const int S = 503, E = 504;
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
	int getAns() {
		int ret = 0;
		int rr = 0;
		while (spfa()) {
			int mn = INF;
			for (int i = E; i != S; i = p[i]) {
				mn = min(mn, eg[p[i]][pidx[i]].c);
			}
			for (int i = E; i != S; i = p[i]) {
				ret += mn * eg[p[i]][pidx[i]].cost;
				eg[p[i]][pidx[i]].c -= mn;
				eg[i][eg[p[i]][pidx[i]].op].c += mn;
			}
			rr = min(rr, ret);
		}
		return rr;
	}
} mf;
int main() {
	int n, a, b, c, x;
	scanf("%d %d %d %d", &n, &a, &b, &c);
	mf.addEdge(0, E, a - 1, 0);
	mf.addEdge(1, E, b - 1, 0);
	mf.addEdge(2, E, c - 1, 0);
	for (int j = 0; j < 3; j++)
		mf.addEdge(j, E, 1, -MAX);
	for (int i = 3; i < 3 + n; i++) {
		mf.addEdge(S, i, 1, 0);
		for (int j = 0; j < 3; j++) {
			scanf("%d", &x);
			mf.addEdge(i, j, 1, -x);
		}
	}
	printf("%d", -mf.getAns() - 3 * MAX);

	return 0;
}