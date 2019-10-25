/*
BOJ 5214 - 환승
https://www.acmicpc.net/problem/5214

한 번 방문한 하이퍼튜브는 다시 방문하지 않아도 된다.
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

/* 🐣🐥 */
bool hp[1001];
int dist[100001];
vector<int> vec[1001], my[100001];
queue<int> q;
int main() {
	int n, k, m, x;
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			scanf("%d", &x);
			vec[i].push_back(x);
			my[x].push_back(i);
		}
	}
	memset(dist, 0x3f, sizeof(dist));
	q.push(1);
	dist[1] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int v : my[cur]) {
			if (hp[v]) continue;
			hp[v] = true;
			for (int vv : vec[v]) {
				if (dist[vv] > dist[cur] + 1) {
					dist[vv] = dist[cur] + 1;
					q.push(vv);
				}
			}
		}
	}
	printf("%d", dist[n] > 1000 ? -1 : dist[n] + 1);

	return 0;
}