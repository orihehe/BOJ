/*
BOJ 16681 (https://www.acmicpc.net/problem/16681)

출발지와 도착지에 대해 다익을 돌려준다.
최소 -100000*100000*100 까지 나올 수 있으므로 INF값 설정에 주의..
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
#define P pair<ll,int>
#define INF 1000000000001
using namespace std;

ll dist[2][100001];
ll h[100001], d, e;
vector<P> vec[100001];
int n, m, a, b;
ll maxS = -INF, c;
void dijk(int cur, int w) {
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push({ 0,cur });
	fill(dist[w], dist[w] + n + 1, INF);
	dist[w][cur] = 0;
	while (!pq.empty()) {
		P nx = pq.top(); pq.pop();
		if (dist[w][nx.second] < nx.first) continue;
		for (P v : vec[nx.second]) {
			ll tmp = v.first + dist[w][nx.second];
			// 오르막길로만 간다
			if (h[v.second] > h[nx.second] && tmp < dist[w][v.second]) {
				dist[w][v.second] = tmp;
				pq.push({ tmp,v.second });
			}
		}
	}
}
int main() {
	scanf("%d %d %lld %lld", &n, &m, &d, &e);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &h[i]);
	}
	while (m--) {
		scanf("%d %d %lld", &a, &b, &c);
		vec[a].push_back({ c,b });
		vec[b].push_back({ c,a });
	}
	dijk(1, 0);
	dijk(n, 1);
	for (int i = 2; i < n; i++) {
		ll tm = h[i] * e - (dist[0][i] + dist[1][i])*d;
		if (tm >= INF) continue;
		maxS = max(maxS, tm);
	}
	if (maxS == -INF) printf("Impossible");
	else printf("%lld", maxS);

	return 0;
}