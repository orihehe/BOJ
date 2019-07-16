/*
BOJ 5944 - Apple Delivery
https://www.acmicpc.net/problem/5944
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define MAX 2000000000
using namespace std;

/* 🐣🐥 */
vector<pii> vec[100001];
int dist[100001], p;
priority_queue<pii, vector<pii>, greater<pii>> pq;
void dijk(int xx) {
	fill(dist, dist + p + 1, MAX);
	dist[xx] = 0;
	pq.push({ 0, xx });
	while (!pq.empty()) {
		pii cur = pq.top();
		pq.pop();
		if (cur.first > dist[cur.second]) continue;
		for (pii v : vec[cur.second]) {
			int tmp = cur.first + v.first;
			if (tmp < dist[v.second]) {
				dist[v.second] = tmp;
				pq.push({ tmp, v.second });
			}
		}
	}
}
int main() {
	int c, pb, pa1, pa2, x, y, z;
	scanf("%d %d %d %d %d", &c, &p, &pb, &pa1, &pa2);
	for (int i = 0; i < c; i++) {
		scanf("%d %d %d", &x, &y, &z);
		vec[x].push_back({ z, y });
		vec[y].push_back({ z, x });
	}
	dijk(pa1);
	int ans = dist[pb] + dist[pa2];
	dijk(pa2);
	ans = min(ans, dist[pb] + dist[pa1]);
	printf("%d", ans);

	return 0;
}