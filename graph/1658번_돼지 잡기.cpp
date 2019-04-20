/*
BOJ 1658 - 돼지 잡기
https://www.acmicpc.net/problem/1658

나중 손님은 이전 손님 중 열쇠가 겹치는 손님의 열린 우리에서 적절히 가져올 수 있으니
손님 사이 간선을 만들어준다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define INF 10000
using namespace std;

/* 🐣🐥 */
int n, m, x, w, f[1102][1102], c[1102][1102], lv[1102], lst[1102], ans;
const int S = 1101, E = 0;
vector<int> vec[1102], sh[1102];
queue<int> q;
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
int dfs(int cur, int flow) {
	if (cur == E) return flow;
	int sz = vec[cur].size();
	for (int i = lst[cur]; i < sz; i++) {
		int v = vec[cur][i];
		if (lv[v] == lv[cur] + 1 && c[cur][v] - f[cur][v] > 0) {
			int df = dfs(v, min(flow, c[cur][v] - f[cur][v]));
			if (df > 0) {
				f[cur][v] += df;
				f[v][cur] -= df;
				lst[cur] = i + 1;
				return df;
			}
		}
	}
	lst[cur] = sz;
	return 0;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		vec[i].push_back(E);
		vec[E].push_back(i);
		c[i][E] = x;
	}
	for (int i = n + 1; i <= n + m; i++) {
		scanf("%d", &x);
		for (int j = 0; j < x; j++) {
			scanf("%d", &w);
			vec[w].push_back(i);
			vec[i].push_back(w);
			c[i][w] = INF;
			sh[w].push_back(i);
		}
		scanf("%d", &x);
		vec[S].push_back(i);
		vec[i].push_back(S);
		c[S][i] = x;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < sh[i].size(); j++) {
			for (int k = j + 1; k < sh[i].size(); k++) {
				c[sh[i][k]][sh[i][j]] = INF;
				vec[sh[i][k]].push_back(sh[i][j]);
				vec[sh[i][j]].push_back(sh[i][k]);
			}
		}
	}
	while (bfs()) {
		memset(lst, 0, sizeof(lst));
		while (true) {
			int ret = dfs(S, INF);
			if (ret == 0) break;
			ans += ret;
		}
	}
	printf("%d", ans);

	return 0;
}