/*
BOJ 14927 (https://www.acmicpc.net/problem/14927)

첫째줄에 대해 모든 경우를 구한다.
그 후 다음줄 부터는 윗줄이 켜져있다면 현재 줄을 켜는 식으로 한다.
첫째줄이 정해져있다면 밑에서 나올 수 있는 경우는 1개뿐
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int arr[18][18],tmp[18][18], n, minC=987654321;
int rgo[5] = { 0,0,1,0,-1 };
int cgo[5] = { 0,1,0,-1,0 };
bool isSame() {
	for (int j = 0; j < n; j++) {
		if (tmp[n-1][j] != 0) {
			return false;
		}
	}
	return true;
}
void dfs(int cur, int cnt) {
	if (cur == n) {
		memcpy(tmp, arr, sizeof(tmp));
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (tmp[i - 1][j] == 1) {
					for (int k = 0; k < 5; k++) {
						int nr = i + rgo[k], nc = j + cgo[k];
						if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
						tmp[nr][nc] ^= 1;
					}
					cnt++;
				}
			}
		}
		if (isSame()) minC = min(minC, cnt);
		return;
	}
	for (int j = 0; j < 5; j++) {
		int nr = 0 + rgo[j], nc = cur + cgo[j];
		if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
		arr[nr][nc] ^= 1;
	}
	dfs(cur + 1, cnt + 1);
	for (int j = 0; j < 5; j++) {
		int nr = 0 + rgo[j], nc = cur + cgo[j];
		if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
		arr[nr][nc] ^= 1;
	}
	dfs(cur + 1, cnt);

}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	dfs(0, 0);
	printf("%d", minC == 987654321 ? -1 : minC);

	return 0;
}