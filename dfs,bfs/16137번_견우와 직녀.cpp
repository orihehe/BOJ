/*
BOJ 16137 - 견우와 직녀
https://www.acmicpc.net/problem/16137

오작교를 놓을 위치를 모두 구하고, 그 위치에 따른 최소시간을 구해준다.
오작교 주기는 그 오작교에 도착했을 때 아직 건널 수 없는 주기라면 q의 뒤에 다시 넣어주는 식으로 처리했다.
주기가 맞기 전엔 큐에서 못나와 그 위치에 머무르게 된다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define MAX 2000000000
using namespace std;

/* 🐣🐥 */
int b[11][11];
int rgo[4] = { 1,-1,0,0 };
int cgo[4] = { 0,0,1,-1 };
bool visited[11][11];
vector<pii> vec; // 놓을 위치
int main() {
	pii cur;
	int n, m, cnt, ans=MAX, s;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) scanf("%d", &b[i][j]);
	}
	// 오작교 놓을 수 있는 위치 모두 저장
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cnt = 0;
			if (b[i][j] != 0) continue;
			for (int k = 0; k < 2; k++) {
				int nr = i + rgo[k], nc = j + cgo[k];
				if (nr < 0 || nc < 0 || nr >= n || nc >= n || b[nr][nc]!=1) continue;
				cnt++;
			}
			if (cnt == 2) {
				vec.push_back({ i,j });
				continue;
			}
			cnt = 0;
			for (int k = 2; k < 4; k++) {
				int nr = i + rgo[k], nc = j + cgo[k];
				if (nr < 0 || nc < 0 || nr >= n || nc >= n || b[nr][nc] != 1) continue;
				cnt++;
			}
			if (cnt == 2) {
				vec.push_back({ i,j });
			}
		}
	}
	vec.push_back({ 0,0 });
	for (pii v : vec) { // 오작교 놓을 위치
		if (v.first != 0 || v.second != 0)
			b[v.first][v.second] = m;
		memset(visited, false, sizeof(visited));
		queue<pii> q;
		q.push({ 0,0 });
		visited[0][0] = true;
		s = 1;
		cnt = 0;
		bool o;
		while (!q.empty()) {
			if (s == 0) {
				s = q.size();
				cnt++;
			}
			cur = q.front();
			q.pop();
			if (cur.first == n - 1 && cur.second == n - 1) {
				ans = min(ans, cnt);
				break;
			}
			o = false; // 오작교에서 온건지
			if (b[cur.first][cur.second] > 1) {
				if (cnt % b[cur.first][cur.second] == 0) {
					o = true;
				}
				else {
					q.push(cur);
					s--;
					continue;
				}
			}
			for (int k = 0; k < 4; k++) {
				int nr = cur.first + rgo[k], nc = cur.second + cgo[k];
				if (nr < 0 || nc < 0 || nr >= n || nc >= n || b[nr][nc]==0 || visited[nr][nc]) continue;
				if (o && b[nr][nc] != 1) continue;
				visited[nr][nc] = true;
				q.push({ nr,nc });
			}
			s--;
		}
		if (v.first != 0 || v.second != 0)
			b[v.first][v.second] = 0;
	}
	printf("%d", ans);
	
	return 0;
}