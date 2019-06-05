/*
BOJ 2316 - 도시 왕복하기
https://www.acmicpc.net/problem/2316

도시는 한번만 방문 가능하니 각 정점을 두 개의 정점으로 나누어 그 사이 간선을 1로 만들어서 풀자
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

/* 🐣🐥 */
vector<int> vec[801];
queue<int> q;
int S, E;
int c[801][801], f[801][801], lv[801], lst[801];
bool bfs() {
	memset(lv, -1, sizeof(lv));
	lv[S] = 0;
	q.push(S);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int v : vec[cur]) {
			if (lv[v] == -1 && c[cur][v] - f[cur][v] > 0) {
				lv[v] = lv[cur] + 1;
				q.push(v);
			}
		}
	}
	return lv[E] != -1;
}
bool dfs(int cur) {
	if (cur == E) return true;
	int sz = vec[cur].size();
	for (int i = lst[cur]; i < sz; i++) {
		int v = vec[cur][i];
		if (lv[v] == lv[cur] + 1 && c[cur][v] - f[cur][v] > 0 && dfs(v)) {
			f[cur][v]++;
			f[v][cur]--;
			return true;
		}
	}
	return false;
}
int main() {
	int n, p, a, b, ans = 0;
	scanf("%d %d", &n, &p);
	S = 1, E = 2 + n;
	for (int i = 1; i <= n; i++) {
		vec[i].push_back(i + n);
		vec[i + n].push_back(i);
		c[i + n][i] = 1;
	}
	while (p--) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b + n);
		vec[b + n].push_back(a);
		vec[a + n].push_back(b);
		vec[b].push_back(a + n);
		c[b][a + n] = c[a][b + n] = 1;
	}
	while (bfs()) {
		memset(lst, 0, sizeof(lst));
		while (dfs(S)) {
			ans++;
		}
	}
	printf("%d", ans);

	return 0;
}