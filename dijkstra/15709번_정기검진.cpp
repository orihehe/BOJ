/*
BOJ 15709 (https://www.acmicpc.net/problem/15709)

������ ������ ���� ���ؼ� �ݵ�� �ٸ��� ���ľ��Ѵ�.
���� �־��� ��� �ٸ��������� ���ͽ�Ʈ��� �ִܰŸ��� ���ϰ�,
�������� �־��� ���� �������� � �ٸ��� ���� �ּ������� �� �� �ִ��� 
��� �ٸ��� dist�迭�� ���캻��.
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