/*
BOJ 17402 - 시간 끌기
https://www.acmicpc.net/problem/17402
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> vec[201];
int B[201];
bool visited[201];
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
	int n, m, k, a, b, cnt = 0;
	scanf("%d %d %d", &n, &m, &k);
	while (k--) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
	}
	memset(B, -1, sizeof(B));
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) cnt++;
	}
	printf("%d", n + m - cnt);

	return 0;
}