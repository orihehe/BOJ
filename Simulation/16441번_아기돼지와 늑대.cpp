/*
전에 못 풀고 남겼던 문제인데 어제 구슬탈출2 문제를 풀고 생각나서 빙판 처리를 해결했다.
백준 구슬탈출2 - https://www.acmicpc.net/problem/13460
*/
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[101][101];
//북 동 남 서
int rgo[4] = { -1,0,1,0 };
int cgo[4] = { 0,1,0,-1 };
int n, m;
char map[101][101];
void dfs(int r, int c) {
	visited[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int nr = r + rgo[i];
		int nc = c + cgo[i];
		while (map[nr][nc] == '+') { // 다음곳이 빙판이면 쭉 미끄러짐
			nr += rgo[i];
			nc += cgo[i];
		}
		if (map[nr][nc] == '#') { // 미끄러진곳 산이면 한칸 뒤로
			nr -= rgo[i];
			nc -= cgo[i];
		}
		if (!visited[nr][nc]) {
			dfs(nr, nc);
		}
	}
}

int main() {
	queue<pair<int, int>> q;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", map[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'W') {
				q.push({ i,j });
			}
		}
	}
	pair<int, int> tmp;
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		dfs(tmp.first, tmp.second);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '.') {
				if (!visited[i][j]) {
					printf("P");
				}
				else printf(".");
			}
			else printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}