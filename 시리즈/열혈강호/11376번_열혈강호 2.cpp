/*
BOJ 11376 - 열혈강호 2
https://www.acmicpc.net/problem/11376

직원 노드를 두 개씩 만들어줘 돌린다.
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
int B[1001];
vector<int> vec[2001];
bool visited[2001];
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
	int n, m, k, ans = 0, x;
	scanf("%d %d", &n, &m);
	memset(B, -1, sizeof(B));
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		for (int j = 0; j < x; j++) {
			scanf("%d", &k);
			vec[i].push_back(k);
			vec[i + n].push_back(k);
		}
	}
	for (int i = 0; i < 2 * n; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) {
			ans++;
		}
	}
	printf("%d", ans);

	return 0;
}