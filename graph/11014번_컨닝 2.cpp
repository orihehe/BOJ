/*
BOJ 11014 - 컨닝 2
https://www.acmicpc.net/problem/11014

짝수 열의 빈 곳을 골라 인접한 왼 3, 오 3과 간선 연결 후
최소 버택스 커버(이분매칭)의 여집합을 구한다.
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> vec[6400];
bool visited[6400];
int B[6400], cgo[6] = { -1,-1,-1,1,1,1 }, rgo[6] = { 1,0,-1,1,0,-1 };
char b[82][82];
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
	int n, m, t, ans, num;
	scanf("%d", &t);
	while (t--) {
		memset(B, -1, sizeof(B));
		ans = 0, num = 0;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%s", b[i]);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (b[i][j] == '.') num++;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j += 2) {
				if (b[i][j] == '.') {
					for (int k = 0; k < 6; k++) {
						int nr = i + rgo[k], nc = j + cgo[k];
						if (nr < 0 || nc < 0 || nr >= n || nc >= m || b[nr][nc] == 'x') continue;
						vec[i*m + j].push_back(nr*m + nc);

					}
				}
			}
		}

		for (int i = 0; i < (n - 1)*m + m; i++) {
			memset(visited, false, sizeof(visited));
			if (dfs(i)) ans++;
		}
		printf("%d\n", num - ans);
		for (int i = 0; i < (n - 1)*m + m; i++) {
			vec[i].clear();
		}
	}

	return 0;
}