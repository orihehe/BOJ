/*
BOJ 1471 - 사탕 돌리기
https://www.acmicpc.net/problem/1471

들어오는 간선이 없는 정점이 없을 때까지 간선 방향으로 정점을 보내주고,
간 정점에 들어오는 정점 수의 최댓값을 저장해둔다.
그리고나서 사이클별로 하위 정점 수의 최댓값 + 사이클 노드 수를 세준다.
*/
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

/* 🐣🐥 */
int sz[200001], to[200001], deg[200001], v, cnt;
queue<int> q;
int nxt(int a) {
	int ret = 0;
	while (a > 0) {
		ret += a % 10;
		a /= 10;
	}
	return ret;
}
void dfs(int cur) {
	deg[cur] = 0;
	cnt++;
	v = max(v, sz[cur]);
	if (deg[to[cur]]) dfs(to[cur]);
}
int main() {
	int n, mx = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		sz[i] = 1;
		to[i] = (i + nxt(i + 1)) % n;
		deg[(i + nxt(i + 1)) % n]++;
	}
	for (int i = 0; i < n; i++) {
		if (!deg[i]) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		sz[to[cur]] = max(sz[to[cur]], sz[cur] + 1);
		deg[to[cur]]--;
		if (!deg[to[cur]]) q.push(to[cur]);
	}
	for (int i = 0; i < n; i++) {
		if (deg[i]) {
			v = 0;
			cnt = 0;
			dfs(i);
			mx = max(mx, cnt+v-1);
		}
	}

	printf("%d", mx);

	return 0;
}