/*
BOJ 17242 - Kaka & Bebe
https://www.acmicpc.net/problem/17242

dist[정점][kaka 개수]로 두고 다익스트라
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/* 🐣🐥 */
int dist[1001][1001];
struct info {
	int op, k, b;
	bool operator <(const info &a) const {
		return b > a.b;
	}
};
vector<info> vec[1001];
priority_queue<info> pq;
int main() {
	int n, m, a, b, kk, bb;
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d %d %d", &a, &b, &kk, &bb);
		vec[a].push_back({ b,kk,bb });
		vec[b].push_back({ a,kk,bb });
	}
	for (int i = 0; i < n; i++)
		fill(dist[i], dist[i] + 1001, 1001);
	dist[0][0] = 0;
	pq.push({ 0,0,0 });
	while (!pq.empty()) {
		info cur = pq.top();
		pq.pop();
		if (cur.b > dist[cur.op][cur.k]) continue;
		for (info v : vec[cur.op]) {
			if (v.k + cur.k > 1000) continue;
			int tmp = v.b + cur.b;
			if (dist[v.op][cur.k + v.k] > tmp) {
				dist[v.op][cur.k + v.k] = tmp;
				pq.push({ v.op,cur.k + v.k,tmp });
			}
		}
	}
	int ans = 1000001;
	for (int i = 1; i <= 1000; i++) {
		if (dist[n - 1][i] != 1001) ans = min(ans, i*dist[n - 1][i]);
	}
	printf("%d", ans == 1000001 ? -1 : ans);

	return 0;
}