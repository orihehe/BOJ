/*
BOJ 11404 - 플로이드
https://www.acmicpc.net/problem/11404
*/
#include <cstdio>
#include <algorithm>
#define INF 10000001
using namespace std;

/* 🐣🐥 */
int dist[101][101];
int main() {
	int n, m, a, b, c;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		fill(dist[i], dist[i] + n, INF);
		dist[i][i] = 0;
	}
	while (m--) {
		scanf("%d %d %d", &a, &b, &c);
		a--, b--;
		dist[a][b] = min(c, dist[a][b]);
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", dist[i][j]==INF ? 0 : dist[i][j]);
		}
		printf("\n");
	}

	return 0;
}