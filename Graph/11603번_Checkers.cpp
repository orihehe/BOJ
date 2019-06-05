/*
BOJ 11603 - Checkers
https://www.acmicpc.net/problem/11603

한 턴에 모든 흰 돌을 없앨 수 있는 검은 돌을 찾는 문제이다.
한 흰돌을 없애는 방법은 ↘ ↙ 두 가지인데, 한 방법을 정하면 다른 돌들의 방향이 정해진다.
따라서 두 가지 경우를 봐주는데, 그 선을 그린 뒤 한붓그리기로 생각하여 풀어주면 된다.
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

char b[27][27];
int arr[27][27];
int wh = -1, fr, fc;
int rgo[4] = { 1,1,-1,-1 }, cgo[4] = { -1,1,1,-1 };
bool visited[27][27];
int n, cnt = 0;
pii aaa;
void dfs(int r, int c) {
	visited[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int nr = r + rgo[i], nc = c + cgo[i];
		if (b[nr][nc] == 'W') {
			arr[r][c]++;
			if (!visited[nr + rgo[i]][nc + cgo[i]]) dfs(nr + rgo[i], nc + cgo[i]);
		}
	}
}
bool vaild() { // 모두 이어져있는지
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cc = 0;
			if (b[i][j] == 'W') {
				for (int k = 0; k < 4; k++) {
					int nr = i + rgo[k], nc = j + cgo[k];
					if (visited[nr][nc]) cc++;
				}
				if (cc == 0) return false;
			}
		}
	}
	return true;
}
void check() {
	bool suc = true;
	if (!vaild()) suc = false;
	int ev = 0, od = 0;
	vector<pii> ovec; // 홀수 좌표
	vector<pii> evec; // 짝수 좌표
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > 0) {
				if (arr[i][j] % 2) { od++; ovec.push_back({ i,j }); }
				else {
					evec.push_back({ i,j });
					ev++;
				}
			}
		}
	}
	pii ans = { -1,-1 };
	if (od == 2) {
		for (pii i : ovec) {
			if (b[i.first][i.second] == 'B') {
				if (ans.first == -1) ans = i;
				else suc = false;
			}
		}
		for (pii i : evec) {
			if (b[i.first][i.second] == 'B') {
				suc = false;
			}
		}
	}
	else if (od == 0) {
		for (pii i : evec) {
			if (b[i.first][i.second] == 'B') {
				if (ans.first == -1) ans = i;
				else suc = false;
			}
		}
	}
	else {
		suc = false;
	}
	if (suc && ans.first != -1) {
		cnt++;
		aaa = ans;
	}
}
int main() {
	scanf("%d", &n);

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			scanf(" %c", &b[i][j]);
			if (b[i][j] == 'W') {
				if (wh == -1) {
					wh = i;
					fr = i, fc = j;
				}
				// 짝수에만, 혹은 홀수에만 있어야함
				else if (fr % 2 != i % 2 || fc % 2 != j % 2) return !printf("None");
				// 가장자리 안됨
				if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
					return !printf("None");
				}
			}
		}
	}
	// 그리기
	dfs(fr - 1, fc - 1);
	check();

	memset(visited, false, sizeof(visited));
	memset(arr, 0, sizeof(arr));
	dfs(fr - 1, fc + 1);
	check();
	
	if (cnt == 1)printf("%c%d\n", aaa.second + 'a', aaa.first + 1);
	else if (cnt == 2) printf("Multiple");
	else printf("None");

	return 0;
}