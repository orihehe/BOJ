/*
BOJ 9525 - 룩 배치하기
https://www.acmicpc.net/problem/9525

행, 열별로 다른 룩과 공유할수 없는 공간을 넘버링 하고 이분매칭
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> vec[5001];
int B[5001], ra[102][103], ca[102][103];
bool visited[5001];
char b[102][103];
int n, x, y, ans, rc, cc;
bool dfs(int cur) {
	visited[cur] = true;
	for (int v : vec[cur]) {
		if (B[v] == -1 || !visited[B[v]] && dfs(B[v])) {
			B[v] = cur;
			return true;
		}
	}
	return false;
}
int main() {
	int p = 0;
	bool chg = true;
	memset(B, -1, sizeof(B));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", b[i]);
	for (int i = 0; i < n; i++) {
		p = 0;
		chg = true;
		while (p < n) {
			if (b[i][p] == '.') {
				ra[i][p] = rc;
				chg = false;
			}
			else {
				if (!chg) {
					chg = true;
					rc++;
				}
			}
			p++;
		}
		rc++;
		
	}
	for (int i = 0; i < n; i++) {
		p = 0;
		chg = true;
		while (p < n) {
			if (b[p][i] == '.') {
				ca[p][i] = cc;
				chg = false;
			}
			else {
				if (!chg) {
					chg = true;
					cc++;
				}
			}
			p++;
		}
		cc++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (b[i][j] != 'X') {
				vec[ra[i][j]].push_back(ca[i][j]);
			}
		}
	}
	
	for (int i = 0; i < rc; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) ans++;
	}
	printf("%d", ans);

	return 0;
}