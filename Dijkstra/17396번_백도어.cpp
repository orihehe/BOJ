/*
BOJ 17396 - 백도어
https://www.acmicpc.net/problem/17396
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
#define pli pair<ll,int>
#define INF 1999999999999999
using namespace std;

/* 🐣🐥 */
bool can[100001];
vector<pli> vec[100001];
priority_queue<pli, vector<pli>, greater <pli>> pq;
ll dist[100001];
ll dijk(int n) {
	fill(dist, dist + n, INF);
	pq.push({ 0,0 });
	dist[0] = 0;
	while (!pq.empty()) {
		pli cur = pq.top();
		pq.pop();
		if (cur.first > dist[cur.second]) continue;
		for (pli v : vec[cur.second]) {
			if (!can[v.second]) continue;
			ll tmp = cur.first + v.first;
			if (tmp < dist[v.second]) {
				dist[v.second] = tmp;
				pq.push({ tmp,v.second });
			}
		}
	}
	if (dist[n - 1] == INF) return -1;
	else return dist[n - 1];
}
int main() {
	int n, m, x, a, b, c;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		can[i] = (x == 0);
	}
	can[n - 1] = true;
	while (m--) {
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back({ c,b });
		vec[b].push_back({ c,a });
	}
	printf("%lld", dijk(n));

	return 0;
}