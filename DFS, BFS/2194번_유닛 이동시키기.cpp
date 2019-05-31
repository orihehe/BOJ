/*
BOJ 2194 - (https://www.acmicpc.net/problem/2194)

상하좌우 네 방향에 대해 유닛을 이동시키고, 
장애물이 없다면 이동가능하므로 큐에 좌표를 넣어준다.
igo함수에서 유닛의 테두리에 장애물이 있는지 검사
*/
#include <cstdio>
#include <queue>
#define P pair<int,int>
using namespace std;

int bo[501][501]; // 장애물 -1, 방문 1
int rgo[4] = { -1,0,1,0 }; // 북 동 남 서
int cgo[4] = { 0,1,0,-1 };
int n, m, a, b, k, r, c, cnt = 0, s = 1;

bool igo(int rr, int cc) {  // 유닛의 테두리 검사
	for (int i = rr; i < rr + a; i++) {
		if (bo[i][cc] == -1) return false;
		if (bo[i][cc + b-1] == -1) return false;
	}
	for (int i = cc; i < cc + b; i++) {
		if (bo[rr][i] == -1) return false;
		if (bo[rr+a-1][i] == -1) return false;
	}
	return true;
}
int main() {
	queue<P> q;
	scanf("%d %d %d %d %d", &n, &m, &a, &b, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &r, &c);
		bo[r][c] = -1;
	}
	scanf("%d %d", &r, &c);
	q.push({ r,c });
	bo[r][c] = 1;
	scanf("%d %d", &r, &c);

	bool suc = false;
	while (!q.empty()) {
		if (s == 0) {
			cnt++;
			s = q.size();
		}
		int cr = q.front().first, cc = q.front().second;
		q.pop();
		if (cr==r && cc==c) {  // 도착
			suc = true; break;
		}
		for (int i = 0; i < 4; i++) {
			int nr = cr + rgo[i], nc = cc + cgo[i];
			if (nr <= 0 || nc <= 0 || nr + a - 1 > n || nc + b - 1 > m) 
				continue;
			// 방문하지 않았고, 장애물이 없다면
			if (bo[nr][nc]!=1 && igo(nr, nc)) {
				q.push({ nr, nc });
				bo[nr][nc] = 1;
			}
		}
		s--;
	}
	if (suc) printf("%d", cnt);
	else printf("-1");

	return 0;
}