/*
BOJ 14433 - 한조 대기 중
https://www.acmicpc.net/problem/14433
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
int B[301];
bool visited[301];
vector<int> vec[301];
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
	int n, m, k1, k2, aa = 0, bb = 0, a, b;
	scanf("%d %d %d %d", &n, &m, &k1, &k2);
	while (k1--) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
	}
	memset(B, -1, sizeof(B));
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) aa++;
	}
	for (int i = 1; i <= n; i++) vec[i].clear();
	while (k2--) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
	}
	memset(B, -1, sizeof(B));
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) bb++;
	}
	if (aa < bb) printf("네 다음 힐딱이");
	else printf("그만 알아보자");

	return 0;
}