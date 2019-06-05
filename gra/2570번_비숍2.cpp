/*
BOJ 2570 - 비숍2
https://www.acmicpc.net/problem/2570
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
bool b[101][101], visited[10101];
int B[10101], rn, cn, rrr[101][101], ccc[101][101];
vector<int> vec[10101];
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
	int n, k, x, y;
	scanf("%d %d", &n, &k);
	while (k--) {
		scanf("%d %d", &x, &y);
		x--, y--;
		b[x][y] = true;
	}
	for (int i = 0; i < n; i++) {
		int nr = 0, nc = i;
		while (nc < n) {
			if (b[nr][nc]) rn++;
			else rrr[nr][nc] = rn;
			nr++, nc++;
		}
		rn++;
	}
	for (int i = 1; i < n; i++) {
		int nr = i, nc = 0;
		while (nr < n) {
			if (b[nr][nc]) rn++;
			else rrr[nr][nc] = rn;
			nr++, nc++;
		}
		rn++;
	}
	for (int i = 0; i < n; i++) {
		int nr = 0, nc = i;
		while (nc >= 0) {
			if (b[nr][nc]) cn++;
			else ccc[nr][nc] = cn;
			nr++, nc--;
		}
		cn++;
	}
	for (int i = 1; i < n; i++) {
		int nr = i, nc = n - 1;
		while (nr < n) {
			if (b[nr][nc]) cn++;
			else ccc[nr][nc] = cn;
			nr++, nc--;
		}
		cn++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!b[i][j])
				vec[rrr[i][j]].push_back(ccc[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < rn; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) {
			ans++;
		}
	}
	printf("%d", ans);

	return 0;
}