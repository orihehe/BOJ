/*
BOJ 5542 - JOI 국가의 행사
https://www.acmicpc.net/problem/5542
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define INF 1987654321
using namespace std;

/* 🐣🐥 */
int dist[100001], p[100001], l[100001], r[100001], ans[100001];
vector<pii> vec[100001];
vector<int> w[200001];
priority_queue<pii, vector<pii>, greater<pii>> pq;
pii Q[100001], ed[200001];
int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	p[a] = b;
}
int n, m, k, q, a, b, c;
void kru() {
	for (int i = 0; i < n; i++) p[i] = i;
	for (int i = 0; i < m; i++) {
		if (find(ed[i].first) != find(ed[i].second))
			merge(ed[i].second, ed[i].first);
		for (int v : w[i]) {
			if (find(Q[v].first) == find(Q[v].second)) {
				r[v] = i - 1;
				ans[v] = min(dist[ed[i].first], dist[ed[i].second]);
			}
			else {
				l[v] = i + 1;
			}
		}
	}
}
int main() {
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		a--, b--;
		ed[i] = { a,b };
		vec[a].push_back({ c,b });
		vec[b].push_back({ c,a });
	}
	fill(dist, dist + n, INF);
	while (k--) {
		scanf("%d", &a);
		a--;
		pq.push({ 0,a });
		dist[a] = 0;
	}
	while (!pq.empty()) {
		pii cur = pq.top();
		pq.pop();
		if (dist[cur.second] < cur.first) continue;
		for (pii v : vec[cur.second]) {
			int tmp = cur.first + v.first;
			if (tmp < dist[v.second]) {
				dist[v.second] = tmp;
				pq.push({ tmp, v.second });
			}
		}
	}
	for (int i = 0; i < q; i++) {
		r[i] = m - 1;
		scanf("%d %d", &a, &b);
		a--, b--;
		Q[i] = { a,b };
	}
	sort(ed, ed + m, [](pii u, pii v) {
		return min(dist[u.first], dist[u.second]) > min(dist[v.first], dist[v.second]);
	});
	while (true) {
		int cnt = 0;
		for (int i = 0; i < m; i++) w[i].clear();
		for (int i = 0; i < q; i++) {
			if (l[i] <= r[i]) {
				w[(l[i] + r[i]) / 2].push_back(i);
				cnt++;
			}
		}
		if (!cnt) break;
		kru();
	}
	for (int i = 0; i < q; i++) printf("%d\n", ans[i]);

	return 0;
}