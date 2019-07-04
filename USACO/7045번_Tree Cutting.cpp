/*
BOJ 7045 - Tree Cutting
https://www.acmicpc.net/problem/7045
*/
#include <cstdio>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> vec[10001];
bool ans[10001];
int n, ch[10001], to;
int dfs(int cur, int p) {
	for (int v : vec[cur]) {
		if (v != p) {
			ch[cur] += dfs(v, cur);
		}
	}
	return ++ch[cur];
}
void go(int cur, int p) {
	bool suc = true;
	if (n - ch[cur] > to) suc = false;
	for (int v : vec[cur]) {
		if (v != p) {
			if (n - ch[v] <= to) go(v, cur);
			if (ch[v] > to) suc = false;
		}
	}
	if (suc) ans[cur] = true;
}
int main() {
	int a, b;
	scanf("%d", &n);
	to = n / 2;
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1, 1);
	go(1, 1);
	for (int i = 1; i <= n; i++) if (ans[i]) printf("%d\n", i);

	return 0;
}