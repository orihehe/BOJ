/*
BOJ 13936 - Iron and Coal
https://www.acmicpc.net/problem/13936

각 정점에서 가장 가까운 iron, 가장 가까운 coal 의 거리를 구한 뒤
1번 정점에서 bfs를 돌리며 최솟값을 구해준다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define ll long long
#define INF 987654321
using namespace std;

/* 🐣🐥 */
queue<int> A, B;
vector<int> vec[100001], rv[100001];
int dist[100001][3];
int main() {
	int n, m, k, x, y;
	scanf("%d %d %d", &n, &m, &k);
	memset(dist, 0x3f, sizeof(dist));
	while (m--) {
		scanf("%d", &x);
		A.push(x);
		dist[x][0] = 0;
	}
	while (k--) {
		scanf("%d", &x);
		B.push(x);
		dist[x][1] = 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		while (x--) {
			scanf("%d", &y);
			vec[i].push_back(y);
			rv[y].push_back(i);
		}
	}
	while (!A.empty()) {
		int cur = A.front();
		A.pop();
		for (int v : rv[cur]) {
			if (dist[v][0] < INF) continue;
			dist[v][0] = dist[cur][0] + 1;
			A.push(v);
		}
	}
	while (!B.empty()) {
		int cur = B.front();
		B.pop();
		for (int v : rv[cur]) {
			if (dist[v][1] < INF) continue;
			dist[v][1] = dist[cur][1] + 1;
			B.push(v);
		}
	}
	A.push(1);
	dist[1][2] = 0;
	int ans = INF;
	while (!A.empty()) {
		int cur = A.front();
		A.pop();
		ans = min((ll)ans, (ll)dist[cur][2] + dist[cur][1] + dist[cur][0]);
		for (int v : vec[cur]) {
			if (dist[v][2] < INF) continue;
			dist[v][2] = dist[cur][2] + 1;
			A.push(v);
		}
	}
	if (ans == INF) printf("impossible");
	else printf("%d", ans);

	return 0;
}