/*
BOJ 1574 - 룩 어택
https://www.acmicpc.net/problem/1574

열 기준으로 행을 살펴보는데, 빈 칸이 없다면 행 위치를 넣어준다.
칸에 룩을 놓는다면 그 열, 행으로는 다른 룩을 놓을 수 없기 때문에 간선이 하나여야만 함.
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> vec[301];
int B[301];
bool visited[301], use[301][301];
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
	int n, m, k, x, y, ans=0;
	scanf("%d %d %d", &n, &m, &k);
	while (k--) {
		scanf("%d %d", &x, &y);
		x--, y--;
		use[x][y] = true;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!use[i][j]) {
				vec[i].push_back(j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) ans++;
	}
	printf("%d", ans);

	return 0;
}