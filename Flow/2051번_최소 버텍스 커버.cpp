/*
BOJ 2051 - 최소 버텍스 커버
https://www.acmicpc.net/problem/2051

L그룹에서 쓰이지 않은 모든 정점에서 이분매칭 dfs를 돌렸을 때
방문되지 않은 L그룹 정점과, 방문된 R그룹 정점이 최소 버텍스 커버 정점이다.
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> vec[1001];
int B[1001], aa, bb;
bool visited[1001], AA[1001], BB[1001], aaa[1001];
bool dfs(int cur, bool x) {
	visited[cur] = true;
	if (x && !AA[cur]) {
		AA[cur] = true;
		aa++;
	}
	for (int v : vec[cur]) {
		if (x && !BB[v]) {
			BB[v] = true;
			bb++;
		}
		if (B[v] == -1 || !visited[B[v]] && dfs(B[v], x)) {
			B[v] = cur;
			return true;
		}
	}
	return false;
}
int main() {
	int n, m, a, x;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		while (a--) {
			scanf("%d", &x);
			vec[i].push_back(x);
		}
	}
	int ans = 0;
	memset(B, -1, sizeof(B));
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i, false)) {
			aaa[i] = true;
			ans++;
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		if (!aaa[i]) {
			dfs(i, true);
		}
	}
	printf("%d\n", ans);
	printf("%d ", n - aa);
	for (int i = 1; i <= n; i++) if (!AA[i]) printf("%d ", i);
	printf("\n%d ", bb);
	for (int i = 1; i <= m; i++) if (BB[i]) printf("%d ", i);

	return 0;
}