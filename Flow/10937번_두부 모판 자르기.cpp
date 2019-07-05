/*
BOJ 10937 - 두부 모판 자르기
https://www.acmicpc.net/problem/10937
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
const int S = 122, E = 123;
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
			ans = max(ans, -ret.second);
		}
		return ret;
	}
} mf;
char b[12][13], idx[150];
int val[4][4] =
{ { 100,70,40,0 },
{ 70,50,30,0 } ,
{ 40,30,20,0 } ,
{ 0,0,0,0 } };
int rgo[4] = { 0,1,0,-1 }, cgo[4] = { 1,0,-1,0 };
int main() {
	int n;
	idx['A'] = 0, idx['B'] = 1, idx['C'] = 2, idx['F'] = 3;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", b[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i + j) % 2) {
				mf.addEdge(i*n + j, E, 1, 0);
			}
			else {
				mf.addEdge(S, i*n + j, 1, 0);
				for (int k = 0; k < 4; k++) {
					int nr = i + rgo[k], nc = j + cgo[k];
					if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
					mf.addEdge(i*n + j, nr*n + nc, 1, -val[idx[b[i][j]]][idx[b[nr][nc]]]);
				}
			}
		}
	}
	mf.getAns();
	printf("%d", ans);

	return 0;
}