/*
BOJ 1867 - 돌멩이 제거
https://www.acmicpc.net/problem/1867

룩문제(BOJ 1574)와 똑같이 풀면됨.
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> vec[500];
bool visited[500];
int B[500];
bool dfs(int cur) {
	visited[cur] = true;
	for (int v : vec[cur]) {
		if (B[v] == -1 || !visited[B[v]] && dfs(B[v])) {
			B[v] = cur;
			return true;
		}
	}
	return false;
}
int main() {
	memset(B, -1, sizeof(B));
	int n, k, a, b, ans = 0;
	scanf("%d %d", &n, &k);
	while (k--) {
		scanf("%d %d", &a, &b);
		a--, b--;
		vec[a].push_back(b);
	}
	for (int i = 0; i < n; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) ans++;
	}
	printf("%d", ans);

	return 0;
}