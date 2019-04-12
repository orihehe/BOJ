/*
BOJ 1348 - 주차장
https://www.acmicpc.net/problem/1348

각 차별로 모든 주차장까지의 시간을 미리 구해 간선을 만들어 놓는다.
그리고나서 이분탐색으로 시간을 정하여 이분매칭!
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
vector<pii> vec[101];
bool visited[101];
int B[101], rgo[4] = { 1,0,-1,0 }, cgo[4] = { 0,-1,0,1 }, dist[51][51], car[51][51];
char arr[51][51];
int rr, cc, mid;
bool dfs(int cur) {
	visited[cur] = true;
	for (pii v : vec[cur]) {
		if (v.first > mid) break;
		if (B[v.second] == -1 || !visited[B[v.second]] && dfs(B[v.second])) {
			B[v.second] = cur;
			return true;
		}
	}
	return false;
}
void chk(int r, int c, int p) {
	memset(dist, -1, sizeof(dist));
	dist[r][c] = 0;
	queue<pii> q;
	q.push({ r,c });
	while (!q.empty()) {
		int ur = q.front().first, uc = q.front().second;
		q.pop();
		if (arr[ur][uc] == 'P')
			vec[p].push_back({ dist[ur][uc],car[ur][uc] });
		for (int i = 0; i < 4; i++) {
			int nr = ur + rgo[i], nc = uc + cgo[i];
			if (nr < 0 || nc < 0 || nr >= rr || nc >= cc || arr[nr][nc] == 'X') continue;
			if (dist[nr][nc] == -1) {
				dist[nr][nc] = dist[ur][uc] + 1;
				q.push({ nr,nc });
			}
		}
	}
}
int main() {
	int n = 0, l, r, ans = -1, cnt = 0;
	scanf("%d %d", &rr, &cc);
	for (int i = 0; i < rr; i++) {
		for (int j = 0; j < cc; j++) {
			scanf(" %c", &arr[i][j]);
			if (arr[i][j] == 'P') car[i][j] = cnt++;
		}
	}
	for (int i = 0; i < rr; i++) {
		for (int j = 0; j < cc; j++) {
			if (arr[i][j] == 'C') {
				chk(i, j, n++);
			}
		}
	}
	l = 0, r = 2501;
	while (l <= r) {
		mid = (l + r) / 2;
		cnt = 0;
		memset(B, -1, sizeof(B));
		for (int i = 0; i < n; i++) {
			memset(visited, false, sizeof(visited));
			if (dfs(i)) {
				cnt++;
			}
		}
		if (cnt == n) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%d", ans);

	return 0;
}