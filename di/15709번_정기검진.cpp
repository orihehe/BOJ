/*
BOJ 15709 (https://www.acmicpc.net/problem/15709)

집에서 병원을 가기 위해선 반드시 다리를 거쳐야한다.
따라서 주어진 모든 다리에서부터 다익스트라로 최단거리를 구하고,
질문에서 주어진 집과 병원으로 어떤 다리를 거쳐 최소한으로 갈 수 있는지 
모든 다리의 dist배열을 살펴본다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define ll long long
#define P pair<ll, int>
#define INF (ll)1e18
using namespace std;

vector<P> vec[20500];
ll dist[101][20500], c;
int n, m, br, b, k, q, a;
void dijk(int cur) {
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push({ 0,cur });
	int u = cur - n - m;
	dist[u][cur] = 0;
	while (!pq.empty()) {
		P nx = pq.top(); pq.pop();
		if (dist[u][nx.second] < nx.first) continue;
		for (P &v : vec[nx.second]) {
			if (dist[u][nx.second] + v.first < dist[u][v.second]) {
				dist[u][v.second] = dist[u][nx.second] + v.first;
				pq.push({ dist[u][v.second],v.second });
			}
		}
	}
}
int main() {
	scanf("%d %d %d %d %d", &n, &m, &br, &k, &q);
	while (k--) {
		scanf("%d %d %lld", &a, &b, &c);
		vec[a].push_back({ c,b });
		vec[b].push_back({ c,a });
	}
	for (int i = 1; i <= br; i++) {
		fill(dist[i], dist[i] + n + m + br + 1, INF);
		dijk(n + m + i);
	}
	while (q--) {
		scanf("%d %d", &a, &b);
		ll ans = INF;
		for (int i = 1; i <= br; i++) {
			ans = min(ans, dist[i][a] + dist[i][b]);
		}
		if (ans >= INF) printf("-1\n");
		else printf("%lld\n", ans);
	}

	return 0;
}