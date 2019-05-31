/*
BOJ 17129 - 윌리암슨수액빨이딱따구리가 정보섬에 올라온 이유
https://www.acmicpc.net/problem/17129

가족의 위치에서부터 가장 가까운 음식에 도달할때까지 bfs를 돌려준다.
*/
#include <cstdio>
#include <queue>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
char b[3001][3001];
int rgo[4] = { 0,1,0,-1 }, cgo[4] = { 1,0,-1,0 };
queue<pii> q;
bool visited[3001][3001];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", b[i]);
		for (int j = 0; j < m; j++) {
			if (b[i][j] == '2') {
				q.push({ i,j });
				visited[i][j] = true;
			}
		}
	}
	int s = 1, cnt = 0;
	while (!q.empty()) {
		if (s == 0) {
			s = q.size();
			cnt++;
		}
		pii cur = q.front();
		q.pop();
		if (b[cur.first][cur.second] >= '3') {
			printf("TAK\n");
			return !printf("%d", cnt);
		}
		for (int i = 0; i < 4; i++) {
			int nr = cur.first + rgo[i], nc = cur.second + cgo[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
			if (b[nr][nc] != '1' && !visited[nr][nc]) {
				q.push({ nr,nc });
				visited[nr][nc] = true;
			}
		}
		s--;
	}
	printf("NIE");

	return 0;
}