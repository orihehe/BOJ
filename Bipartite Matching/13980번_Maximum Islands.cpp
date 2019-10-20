/*
BOJ 13980 - Maximum Islands
https://www.acmicpc.net/problem/13980

L과 인접한 C를 모두 X로 만들어주고 남은 C에 대해 최소 버택스 커버(이분매칭)의 여집합을 구해준다.
간선은 십자로 이어주기, 체스판의 검은 위치만
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> vec[1600];
bool visited[1600], chk[41][41];
int B[1600], cgo[4] = { 1,0,-1,0 }, rgo[4] = { 0,-1,0,1 };
char b[42][42];
int n, m, ans, num;
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
void sl(int r, int c) {
	chk[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int nr = r + rgo[i], nc = c + cgo[i];
		if (nr < 0 || nc < 0 || nr >= n || nc >= m || chk[nr][nc]) continue;
		if (b[nr][nc] == 'C') {
			b[nr][nc] = 'X';
		}
		if(b[nr][nc]=='L')
			sl(nr, nc);
	}
}
int main() {
	memset(B, -1, sizeof(B));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", b[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[i][j] == 'L' && !chk[i][j]) {
				sl(i, j);
				num++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[i][j] == 'C') num++;
			if ((i + j) % 2 || b[i][j] != 'C') continue;

			for (int k = 0; k < 4; k++) {
				int nr = i + rgo[k], nc = j + cgo[k];
				if (nr < 0 || nc < 0 || nr >= n || nc >= m || b[nr][nc] != 'C') continue;
				vec[i*m + j].push_back(nr*m + nc);
			}
		}
	}

	for (int i = 0; i < (n - 1)*m + m; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) ans++;
	}
	printf("%d\n", num - ans);


	return 0;
}