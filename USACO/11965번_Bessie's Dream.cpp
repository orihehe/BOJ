/*
BOJ 11965 - Bessie's Dream
https://www.acmicpc.net/problem/11965

visited배열을 x,y,냄새여부 로 정의한다.
타일이 보라색일 때 여러칸 가주니 pq로 넣어 
현재 위치까지의 시간보다 작을 때만 큐에 넣어줬다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX 2000000000
using namespace std;

/* 🐣🐥 */
struct node {
	int r, c, t; // t는 도착시간
	int sm; // 냄새
	bool operator < (const node &a)const {
		return t > a.t;
	}
};
int b[1001][1001]; 
int visited[1001][1001][2];// r, c, 냄새, 방향
int rgo[4] = { 0,0,1,-1 };
int cgo[4] = { 1,-1,0,0 };
priority_queue<node> pq;
int main() {
	int n, m, ans = MAX;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &b[i][j]);
		}
	}
	memset(visited, -1, sizeof(visited));
	pq.push({ 0,0,0, false });
	visited[0][0][0] = 0;
	while (!pq.empty()) {
		node cur = pq.top();
		node tmp;
		pq.pop();
		if (b[cur.r][cur.c] == 3 && !cur.sm) { // 파랑인데 냄새 안나고있으면
			continue;
		}
		if (cur.r == n - 1 && cur.c == m - 1) continue;
		for (int i = 0; i < 4; i++) {
			int nr = cur.r + rgo[i], nc = cur.c + cgo[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m || b[nr][nc] == 0) continue;
			tmp = cur;
			tmp.r = nr;
			tmp.c = nc;
			tmp.t++;
			if (b[nr][nc] == 4) { // 슬라이딩
				int cc = 0;
				while (nr >= 0 && nc >= 0 && nr < n && nc < m && b[nr][nc] == 4) {
					nr += rgo[i];
					nc += cgo[i];
					cc++;
				}
				if (nr < 0 || nc < 0 || nr >= n || nc >= m || b[nr][nc] == 0
					 || (b[nr][nc]==3 && tmp.sm==0)) {
					cc--;
					nr -= rgo[i];
					nc -= cgo[i];
				}
				tmp.r = nr;
				tmp.c = nc;
				tmp.t += cc;
				if (visited[nr][nc][tmp.sm] == -1 || visited[nr][nc][tmp.sm] > tmp.t) {
					visited[nr][nc][tmp.sm] = tmp.t;
					if (b[nr][nc] == 2) {
						tmp.sm = 1;
					}
					else
						tmp.sm = 0;
					pq.push(tmp);
				}
			}
			else if (visited[nr][nc][tmp.sm]==-1 || visited[nr][nc][tmp.sm] > tmp.t) {
				visited[nr][nc][tmp.sm] = tmp.t;
				if (b[nr][nc] == 2) {
					tmp.sm = 1;
				}
				pq.push(tmp);
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		if (visited[n - 1][m - 1][i] != -1)
			ans = min(ans, visited[n - 1][m - 1][i]);
	}
	if(ans==MAX) printf("-1");
	else printf("%d", ans);

	return 0;
}