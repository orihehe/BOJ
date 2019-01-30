/*
BOJ 15944 (https://www.acmicpc.net/problem/15944)

폭발 범위를 모두 살펴보지 않고, 테두리만 살펴봐줍니다.
범위 안에 있는 길이 범위 밖으로 나가지 않는다면 횟수는 똑같기 때문
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define P pair<int,int>
using namespace std;

char b[501][501];
int visited[501][501];
int rgo[4] = { 0,1,0,-1 };
int cgo[4] = { 1,0,-1,0 };
int n, m, d, tmp;
queue<P> q;
void dfs(int r, int c, int val) {
	if (visited[r][c] != -1) return;
	visited[r][c] = val;
	q.push({ r,c });
	for (int i = 0; i < 4; i++) {
		int nr = r + rgo[i], nc = c + cgo[i];
		if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
		if (visited[nr][nc] == -1 && b[nr][nc] == '.') dfs(nr, nc, val);
	}
}
int main() {
	scanf("%d %d %d", &n, &m, &d);
	for (int i = 0; i < n; i++) {
		scanf("%s", b[i]);
	}
	memset(visited, -1, sizeof(visited));
	dfs(0, 0, 0);
	while (!q.empty()) {
		P nx = q.front(); q.pop();
		if (visited[n - 1][m - 1] != -1) break;
		for (int i = nx.first - d + 1; i <= nx.first + d - 1; i++) {
			if (i < 0 || i >= n) continue;
			tmp = min(nx.second + d, m - 1);
			dfs(i, tmp, visited[nx.first][nx.second] + 1);

			tmp = max(nx.second - d, 0);
			dfs(i, tmp, visited[nx.first][nx.second] + 1);
		}
		for (int i = nx.second - d + 1; i <= nx.second + d - 1; i++) {
			if (i < 0 || i >= m) continue;
			tmp = min(nx.first + d, n - 1);
			dfs(tmp, i, visited[nx.first][nx.second] + 1);

			tmp = max(nx.first - d, 0);
			dfs(tmp, i, visited[nx.first][nx.second] + 1);
		}
	}
	printf("%d", visited[n - 1][m - 1]);

	return 0;
}