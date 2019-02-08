/*
BOJ 16156 (https://www.acmicpc.net/problem/16156)

도착지점을 모두 pq에 넣고 시작
가장 먼저 1번째 열에 도착한 fr정보를 카운트 해준다
*/
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int b[500][500], d[500][500], p[500], n, m;
int rgo[4] = { 0,1,0,-1 }, cgo[4] = { 1,0,-1,0 };
struct info {
	int val, r, c, fr;
	bool operator < (const info &a) const {
		return val > a.val;
	}
};
void dijk() {
	priority_queue<info> pq;
	for (int i = 0; i < n; i++) {
		pq.push({ b[i][m - 1],i,m - 1, i });
		d[i][m - 1] = b[i][m - 1];
	}
	while (!pq.empty()) {
		info nx = pq.top(); pq.pop();
		if (d[nx.r][nx.c] < nx.val) continue;
		if (nx.c == 0) {
			p[nx.fr]++;
		}
		for (int i = 0; i < 4; i++) {
			int nr = nx.r + rgo[i], nc = nx.c + cgo[i];
			if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
				int t = d[nx.r][nx.c] + b[nr][nc];
				if (t < d[nr][nc]) {
					pq.push({ t,nr,nc,nx.fr });
					d[nr][nc] = t;
				}
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%d", &b[i][j]);
		fill(d[i], d[i] + m, 2000000000);
	}
	dijk();
	for (int i = 0; i < n; i++) printf("%d\n", p[i]);
	return 0;
}