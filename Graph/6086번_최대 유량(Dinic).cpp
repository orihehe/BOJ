/*
BOJ 6086 - 최대 유량
https://www.acmicpc.net/problem/6086
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

/* 🐣🐥 */
int c[60][60], f[60][60], lv[60], lst[60];
vector<int> vec[60];
const int S = 0, E = 'Z' - 'A';
queue<int> q;
bool bfs() { // 레벨
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
	if (lv[E] == -1) return false;
	else return true;
}
int dfs(int cur, int flow) { // 흘리기
	if (cur == E) return flow;
	int sz = vec[cur].size();
	for (int i = lst[cur]; i < sz; i++) {
		int v = vec[cur][i];
		if (lv[cur] + 1 == lv[v] && c[cur][v] - f[cur][v] > 0) {
			int df = dfs(v, min(flow, c[cur][v] - f[cur][v]));
			if (df > 0) {
				f[cur][v] += df;
				f[v][cur] -= df;
				return df;
			}
		}
		lst[cur] = i;
	}
	return 0;
}
void rm(char &st) { // 알파벳 -> 숫자
	if (st >= 'A' && st <= 'Z') st -= 'A';
	else st = st - 'a' + 26;
}
int main() {
	int n, fo, ans = 0;
	char s, e;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c %c %d", &s, &e, &fo);
		rm(s), rm(e);
		vec[s].push_back(e);
		vec[e].push_back(s);
		c[s][e] += fo; 
		c[e][s] = c[s][e];
	}
	while (bfs()) {
		memset(lst, 0, sizeof(lst));
		while (true) {
			int flow = dfs(S,1001);
			if (flow == 0) break;
			ans += flow;
		}
	}
	printf("%d", ans);

	return 0;
}