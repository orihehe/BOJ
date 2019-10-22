/*
BOJ 13907 - 세금
https://www.acmicpc.net/problem/13907
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define INF 1987654321
using namespace std;

/* 🐣🐥 */
int dist[1001][1001];
int n, m, k, s, e, a, b, c, sum;
vector<pii> vec[1001];
struct info {
	int val, v, cnt;
	bool operator <(const info &a) const {
		return val > a.val;
	}
};
void dijk(int S) {
	priority_queue<info> pq;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dist[i][j] = INF;
	dist[S][0] = 0;
	pq.push({ 0,S,0 });
	while (!pq.empty()) {
		info cur = pq.top();
		pq.pop();
		if (cur.cnt == n) continue;
		if (cur.val > dist[cur.v][cur.cnt]) continue;
		for (pii v : vec[cur.v]) {
			int tmp = cur.val + v.first;
			if (tmp < dist[v.second][cur.cnt + 1]) {
				dist[v.second][cur.cnt + 1] = tmp;
				pq.push({ tmp,v.second,cur.cnt + 1 });
			}
		}
	}
}
int main() {
	scanf("%d %d %d", &n, &m, &k);
	scanf("%d %d", &s, &e);
	while (m--) {
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back({ c,b });
		vec[b].push_back({ c,a });
	}
	dijk(s);
	for (int i = 0; i <= k; i++) {
		if (i) {
			scanf("%d", &a);
			sum += a;
		}
		int ans = INF;
		for (int j = 1; j <= n; j++) {
			if (dist[e][j] == INF) continue;
			ans = min(ans, dist[e][j] + j * sum);
		}
		printf("%d\n", ans);
	}

	return 0;
}