/*
BOJ 3654 - L퍼즐
https://www.acmicpc.net/problem/3654
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

/* 🐣🐥 */
char bb[501][501];
vector<int> vec[2000001], sta, ww;
int n, m, op, cnt, scnt, fn[2000001], num[2000001];
int rgo[4] = { 0,-1,0,1 }, cgo[4] = { 1,0,-1,0 }; // 동 북 서 남
bool suc;
int getOP(int cur) {
	return cur + (cur < op ? op : -op);
}
int dfs(int cur) {
	num[cur] = ++cnt;
	sta.push_back(cur);

	int ret = num[cur];
	for (int v : vec[cur]) {
		if (!num[v]) ret = min(ret, dfs(v));
		else if (!fn[v]) ret = min(ret, num[v]);
	}
	if (ret == num[cur]) {
		scnt++;
		while (sta.size()) {
			int nx = sta.back();
			sta.pop_back();
			fn[nx] = scnt;
			if (fn[getOP(nx)] == fn[nx]) suc = false;
			if (nx == cur) break;
		}
	}
	return ret;
}
void NAND(int a, int b) {
	vec[a].push_back(getOP(b));
	vec[b].push_back(getOP(a));
}
void NOT(int a) {
	vec[a].push_back(getOP(a));
}
void XOR(int a, int b) {
	vec[a].push_back(getOP(b));
	vec[b].push_back(getOP(a));
	vec[getOP(a)].push_back(b);
	vec[getOP(b)].push_back(a);
}
int main() {
	int t, B = 0, W = 0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		op = n * m * 4;
		W = B = 0;
		scnt = cnt = 0;
		for (int i = 0; i < op * 2; i++) vec[i].clear();
		suc = true;
		memset(num, 0, sizeof(num));
		memset(fn, 0, sizeof(fn));

		for (int i = 0; i < n; i++) scanf("%s", bb[i]);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (bb[i][j] == 'W') {
					W++;
					ww.clear();
					for (int k = 0; k < 4; k++) {
						int nr = i + rgo[k];
						int nc = j + cgo[k];
						if (nr < 0 || nc < 0 || nr >= n || nc >= m || bb[nr][nc] != 'B') continue;
						ww.push_back((nr*m + nc) * 4 + k);
					}
					for (int k = 0; k < ww.size(); k++) {
						for (int kk = k + 1; kk<ww.size(); kk++)
							NAND(ww[k], ww[kk]);
					}
				}
				else if (bb[i][j] == 'B') {
					B++;
					if (i - 1 < 0 || bb[i - 1][j] != 'W')
						NOT((i*m + j) * 4 + 3);
					if (i + 1 >= n || bb[i + 1][j] != 'W')
						NOT((i*m + j) * 4 + 1);
					XOR((i*m + j) * 4 + 3, (i*m + j) * 4 + 1);
					if (j - 1 < 0 || bb[i][j - 1] != 'W')
						NOT((i*m + j) * 4);
					if (j + 1 >= m || bb[i][j + 1] != 'W')
						NOT((i*m + j) * 4 + 2);
					XOR((i*m + j) * 4 + 2, (i*m + j) * 4);
				}
			}
		}
		if (2 * B != W) {
			printf("NO\n");
			continue;
		}
		for (int i = 0; i < op * 2; i++) {
			if (!num[i]) dfs(i);
		}
		if (suc) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}