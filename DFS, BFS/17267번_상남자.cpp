/*
BOJ 17267 - 상남자
https://www.acmicpc.net/problem/17267

위아래는 덱의 앞에 넣고, 좌우는 덱의 뒤에 넣어준다.
어떤 칸에 좌우를 최소로 사용하고 가는 것!
*/
#include <cstdio>
#include <queue>
using namespace std;

/* 🐣🐥 */
struct info {
	int r, c, le, ri;
};
char b[1001][1002];
bool visited[1001][1001];
int n, m, ans, rgo[4] = { 1,0,-1,0 }, cgo[4] = { 0,1,0,-1 };
deque<info> dq;
int main() {
	int l, r;
	scanf("%d %d %d %d", &n, &m, &l, &r);
	for (int i = 0; i < n; i++) scanf("%s", b[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (b[i][j] == '2') {
				dq.push_back({ i,j,l,r });
				visited[i][j] = true;
			}
	while (!dq.empty()) {
		info cur = dq.front();
		dq.pop_front();
		ans++;
		for (int i = 0; i < 4; i++) {
			int nr = cur.r + rgo[i], nc = cur.c + cgo[i];
			if (nr >= n || nc >= m || nr < 0 || nc < 0 || visited[nr][nc] || b[nr][nc] == '1') continue;
			if (i == 1 && cur.ri > 0) {
				visited[nr][nc] = true;
				dq.push_back({ nr,nc,cur.le,cur.ri - 1 });
			}
			else if (i == 3 && cur.le > 0) {
				visited[nr][nc] = true;
				dq.push_back({ nr,nc,cur.le - 1,cur.ri });
			}
			else if (i % 2 == 0) {
				visited[nr][nc] = true;
				dq.push_front({ nr,nc,cur.le,cur.ri });
			}
		}
	}
	printf("%d", ans);

	return 0;
}