/*
BOJ 16726 - 영과일 학회방
https://www.acmicpc.net/problem/16726

1x2 타일을 최대한 많이 배치하면 최소 타일 개수가 나온다.
현재 위치에서 4방향으로 타일을 놨을 때 그 방향은 타일을 다시 놓을 수 없으니 현재 정점에서 간선을 만들어주는데,
이것을 체스판의 흰색에서만 위치를 보면 겹치지 않게 이분그래프로 만들 수 있다.
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
char b[52][53];
bool visited[2501];
vector<int> vec[2501];
int B[2501], rgo[4] = { 1,0,-1,0 }, cgo[4] = { 0,1,0,-1 };
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
	int n, m, ans = 0, num = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &b[i][j]);
			if (b[i][j] == '.') num++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i + j) % 2 || b[i][j] == 'X') continue;
			for (int k = 0; k < 4; k++) {
				int nr = i + rgo[k], nc = j + cgo[k];
				if (nr < 0 || nc < 0 || nr >= n || nc >= m || b[nr][nc] == 'X') continue;
				vec[i*m + j].push_back(nr*m + nc);
			}
		}
	}
	for (int i = 0; i < (n - 1)*m + m; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) ans++;
	}
	printf("%d", ans + num - 2*ans);

	return 0;
}