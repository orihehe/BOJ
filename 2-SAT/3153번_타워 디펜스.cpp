/*
BOJ 3153 - 타워 디펜스
https://www.acmicpc.net/problem/3153

각 클론에는 최대 가로1, 세로1 의 타워가 쏠 수 있다.
한 가로나 세로에 쏠 수 있는 타워가 2개라면 타워끼리 부딪히니 고려하지 않는다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int rgo[4] = { -1,0,1,0 }, cgo[4] = { 0,1,0,-1 }, ap, op;
int n, m, num[80001], cnt, scnt, tw[101][101];
pii fn[80001];
vector<int> vec[80001];
stack<int> sta;
char brd[101][102];
bool visited[80001];
int getOP(int cur) {
	return cur + (cur > op ? -op : op);
}
int dfs(int cur) {
	num[cur] = ++cnt;
	sta.push(cur);

	int ret = num[cur];
	for (int v : vec[cur]) {
		if (!num[v]) ret = min(ret, dfs(v));
		else if (!fn[v].first) ret = min(ret, num[v]);
	}
	if (ret == num[cur]) {
		scnt++;
		while (true) {
			int nx = sta.top();
			sta.pop();
			fn[nx].first = scnt;
			fn[nx].second = nx;
			if (nx == cur) break;
		}
	}
	return ret;
}
bool cmp(pii a, pii b) {
	return a.first > b.first;
}
// 타워끼리 부딪히는 경우 처리
void find_t(int rr, int cc, int cur) {
	for (int i = 0; i < 4; i++) {
		int nr = rr + rgo[i], nc = cc + cgo[i];
		int nx = cur * 4 + i;
		while (nr > 0 && nc > 0 && nr <= n && nc <= m) {
			if (brd[nr][nc] == '#') break;
			if (brd[nr][nc] == 'T') {
				vec[nx].push_back(getOP(nx));
				break;
			}
			nr += rgo[i], nc += cgo[i];
		}
	}
}
// 클론에 대포를 쏠 수 있는 타워 탐색
void find(int rr, int cc) {
	int dir[4] = { -1,-1,-1,-1 };
	int rl[2] = { 0,0 }, rp = 0;
	for (int i = 0; i < 4; i++) {
		int nr = rr + rgo[i], nc = cc + cgo[i];
		while (nr > 0 && nc > 0 && nr <= n && nc <= m) {
			if (brd[nr][nc] == '#') break;
			if (brd[nr][nc] == 'T') {
				dir[(i + 2) % 4] = tw[nr][nc];
				break;
			}
			nr += rgo[i], nc += cgo[i];
		}
	}
	if (dir[0] != -1 && dir[2] != -1) {}
	else if (dir[0] != -1) rl[rp++] = dir[0] * 4;
	else if (dir[2] != -1) rl[rp++] = dir[2] * 4 + 2;
	if (dir[1] != -1 && dir[3] != -1) {}
	else if (dir[1] != -1) rl[rp++] = dir[1] * 4 + 1;
	else if (dir[3] != -1) rl[rp++] = dir[3] * 4 + 3;

	// a타워에서 쏘거나, b타워에서 쏘거나 (or)
	if (rp == 2) {
		vec[getOP(rl[0])].push_back(rl[1]);
		vec[getOP(rl[1])].push_back(rl[0]);
	}
	// a타워에서 무조건 쏴야함
	else if (rp == 1) {
		vec[getOP(rl[0])].push_back(rl[0]);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", brd[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (brd[i][j] == 'T')
				tw[i][j] = ap++;

	op = ap * 4;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (brd[i][j] == 'T') {
				find_t(i, j, tw[i][j]);

				// 타워의 각 방향을 묶어준다.
				// 북 a 동 b 남 c 서 d 라고 하면
				// (a xor c) and (b xor d)
				int aa = tw[i][j] * 4;
				vec[getOP(aa)].push_back(aa + 2);
				vec[getOP(aa + 2)].push_back(aa);
				vec[aa + 2].push_back(getOP(aa));
				vec[aa].push_back(getOP(aa + 2));

				vec[getOP(aa + 1)].push_back(aa + 3);
				vec[getOP(aa + 3)].push_back(aa + 1);
				vec[aa + 3].push_back(getOP(aa + 1));
				vec[aa + 1].push_back(getOP(aa + 3));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (brd[i][j] == 'n') {
				find(i, j);
			}
		}
	}
	for (int i = 0; i < ap * 8; i++)
		if (!num[i]) dfs(i);
	sort(fn, fn + ap * 8, cmp);
	for (int i = 0; i < ap * 8; i++) {
		if (!visited[getOP(fn[i].second)]) visited[fn[i].second] = true;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (brd[i][j] == 'T') {
				int cur = tw[i][j] * 4;
				if (!visited[cur] && !visited[cur + 1]) brd[i][j] = '3';
				else if (!visited[cur + 1] && !visited[cur + 2]) brd[i][j] = '2';
				else if (!visited[cur + 2] && !visited[cur + 3]) brd[i][j] = '1';
				else if (!visited[cur + 3] && !visited[cur]) brd[i][j] = '4';
			}
		}
	}
	for (int i = 1; i <= n; i++) printf("%s\n", brd[i] + 1);

	return 0;
}