/*
BOJ 3044 - 자전거 경주 준비하기
https://www.acmicpc.net/problem/3044

먼저 1에서 갈 수 없는 정점들을 없애준다.
그리고나서 각 정점에 대해 그 정점으로 올 수 있는 정점들을 저장하고,
위상정렬 후 2번정점을 타고 올라가서 deg가 남아있는지 확인.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define mod 1000000000
using namespace std;

/* 🐣🐥 */
int deg[10001], r[10001];
vector<int> vec[10001], p[10001];
queue<int> q;
bool visited[10001], suc = true;
void dfs(int cur) {
	visited[cur] = true;
	for (int v : vec[cur]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
}
void dd(int cur) {
	visited[cur] = true;
	if (deg[cur]>0) suc = false;
	for (int v : p[cur]) {
		if (!visited[v]) {
			dd(v);
		}
	}
}
int main() {
	int n, m, a, b;
	bool ss = false;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		deg[b]++;
		vec[a].push_back(b);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			for (int v : vec[i]) {
				deg[v]--;
			}
		}
	}
	q.push(1);
	for (int i = 1; i <= n; i++) {
		if (visited[i]) {
			for (int v : vec[i]) {
				p[v].push_back(i);
			}
		}
	}
	r[1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int v : vec[cur]) {
			if (r[v] + r[cur] >= mod) ss = true;
			r[v] = (r[v] + r[cur]) % mod;
			deg[v]--;
			if (!deg[v]) q.push(v);
		}
	}

	memset(visited, false, sizeof(visited));
	dd(2);

	if (!suc) return !printf("inf");
	if (ss) printf("%09d", r[2]);
	else printf("%d", r[2]);

	return 0;
}