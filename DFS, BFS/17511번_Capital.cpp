/*
BOJ 17511 - Capital
https://www.acmicpc.net/problem/17511
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> vec[501], ans;
bool visited[501];
int cnt = 0;
void dfs(int cur) {
	visited[cur] = true;
	cnt++;
	for (int &v : vec[cur]) {
		if (!visited[v]) dfs(v);
	}
}
int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		cnt = 0;
		dfs(i);
		if (cnt == n) {
			ans.push_back(i);
		}
	}
	printf("%d\n", ans.size());
	for (int v : ans) printf("%d ", v);

	return 0;
}