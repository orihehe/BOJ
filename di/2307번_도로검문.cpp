/*
BOJ 2307 (https://www.acmicpc.net/problem/2307)

1에서 n으로 가는 최단거리가 바뀌는 경우는 1에서 n으로 가는 간선중에서 검문을 했을 경우이다.
따라서 먼저 최단거리를 구하고, 경로를 역추적하여 얻은 간선들만 하나씩 검문을 해서 지연시간을 구한다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define INF 50000001
using namespace std;

int dist[1001], p[1001];
int n, m, a, b, c, minV, maxT, ba, bb;
vector<pii> vec[1001];
vector<pii> ans;
void dijk(int cur) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	fill(dist, dist + n + 1, INF);
	dist[cur] = 0;
	pq.push({ 0,cur });
	while (!pq.empty()) {
		pii nx = pq.top(); pq.pop();
		if (dist[nx.second] < nx.first) continue;
		for (pii v : vec[nx.second]) {
			if (nx.second == ba && v.second == bb) continue;
			if (nx.second == bb && v.second == ba) continue;
			int tmp = v.first + nx.first;
			if (tmp < dist[v.second]) {
				dist[v.second] = tmp;
				p[v.second] = nx.second;
				pq.push({ tmp,v.second });
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back({ c,b });
		vec[b].push_back({ c,a });
	}
	dijk(1);
	minV = dist[n];
	ans.push_back({ n,p[n] });
	for (int i = p[n]; i != 1; i = p[i]) {
		ans.push_back({ i,p[i] });
	}
	for (pii v : ans) {
		ba = v.first; bb = v.second;
		dijk(1);
		if (dist[n] == INF) return !printf("-1");
		maxT = max(maxT, dist[n] - minV);
	}
	printf("%d", maxT);

	return 0;
}