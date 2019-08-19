/*
BOJ 15019 - Distinctive Character
https://www.acmicpc.net/problem/15019

현재 수에서 한 비트씩 다른 수로 거리 1을 두어 bfs
같은 수의 개수의 최댓값을 최소화 하는 문제가
다른 수의 개수가 가장 작은 것의 최댓값을 구하는 문제와 같다.
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#define INF 1999999999
using namespace std;

/* 🐣🐥 */
char b[100001][21];
int dist[1048577];
queue<int> q;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	fill(dist, dist + (1 << m), INF);
	for (int i = 0; i < n; i++) {
		scanf("%s", b[i]);
		int tmp = 0, tt = 1;
		for (int j = m - 1; j >= 0; j--) {
			if (b[i][j] - '0') tmp += tt;
			tt *= 2;
		}
		dist[tmp] = 0;
		q.push(tmp);
	}
	int ans;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		ans = cur;
		int tt = 1;
		for (int i = 0; i < m; i++) {
			if (dist[cur^tt] == INF) {
				q.push(cur^tt);
				dist[cur^tt] = dist[cur] + 1;
			}
			tt *= 2;
		}
	}
	int tt = 1 << (m - 1);
	for (int i = 0; i < m; i++) {
		printf("%d", ((ans & tt) == tt) ? 1 : 0);
		tt /= 2;
	}

	return 0;
}