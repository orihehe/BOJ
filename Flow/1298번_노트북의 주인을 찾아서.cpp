/*
BOJ 1298 - 노트북의 주인을 찾아서
https://www.acmicpc.net/problem/1298

이분매칭 기본문제
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> vec[101];
bool visited[101];
int B[101];
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
	int n, m, ans = 0, a, b;
	memset(B, -1, sizeof(B));
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) {
			ans++;
		}
	}
	printf("%d", ans);

	return 0;
}