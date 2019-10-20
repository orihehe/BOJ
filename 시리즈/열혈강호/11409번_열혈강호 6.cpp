/*
BOJ 11409 - 열혈강호 6
https://www.acmicpc.net/problem/11409
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
struct edg {
	int u, v, c, op, cost;
};
const int S = 801, E = 802;
vector<edg> eg;
vector<int> vec[803];
int dist[803], p[803];
bool inq[803];
bool SPFA() {
	memset(p, -1, sizeof(p));
	memset(inq, false, sizeof(inq));
	fill(dist, dist + 803, INF);
	queue<int> q;
	dist[S] = 0;
	inq[S] = true;
	q.push(S);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		inq[cur] = false;
		for (int v : vec[cur]) {
			edg i = eg[v];
			if (i.c > 0 && i.cost + dist[cur] < dist[i.v]) {
				dist[i.v] = i.cost + dist[cur];
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
pii MCMF() {
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
void aeg(int a, int b, int c, int cost) {
	int sz = eg.size();
	edg e1 = { a,b,c,sz + 1,-cost };
	edg e2 = { b,a,0,sz, cost };
	eg.push_back(e1);
	eg.push_back(e2);
	vec[a].push_back(sz);
	vec[b].push_back(sz + 1);
}
int main() {
	int n, m, x, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		aeg(S, i, 1, 0);
		scanf("%d", &x);
		while (x--) {
			scanf("%d %d", &a, &b);
			a--;
			aeg(i, a + n, 1, b);
		}
	}
	for (int i = n; i < m + n; i++) aeg(i, E, 1, 0);
	pii ans = MCMF();
	printf("%d\n%d", ans.first, -ans.second);

	return 0;
}