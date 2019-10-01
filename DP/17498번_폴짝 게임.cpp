/*
BOJ 17498 - 폴짝 게임
https://www.acmicpc.net/problem/17498
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define INF 2000000001
using namespace std;

/* 🐣🐥 */
int arr[200001];
int dist[200001];
int main() {
	int n, m, d;
	scanf("%d %d %d", &n, &m, &d);
	for (int i = 0; i < n*m; i++) scanf("%d", &arr[i]);
	fill(dist, dist + n * m, -INF);
	for (int i = 0; i < m; i++) dist[i] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int x = 1; x <= d; x++) {
				for (int y = -d; y <= d; y++) {
					if (x + abs(y) > d) continue;
					int nr = i + x, nc = j + y;
					if (nr >= n || nc < 0 || nc >= m) continue;
					dist[nr*m + nc] = max(dist[nr*m + nc], dist[i*m + j] + arr[i*m + j] * arr[nr*m + nc]);
				}
			}
		}
	}
	int ans = -INF;
	for (int i = 0; i < m; i++) {
		ans = max(ans, dist[(n - 1)*m + i]);
	}
	printf("%d", ans);

	return 0;
}