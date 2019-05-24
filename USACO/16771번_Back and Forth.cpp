/*
BOJ 16771 - Back and Forth
https://www.acmicpc.net/problem/16771
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int arr[2][14], b[12], ans;
bool can[1500];
void dfs(int cnt, int cur) {
	if (cnt == 4) {
		if (!can[cur]) ans++;
		can[cur] = true;
		return;
	}
	for (int i = 0; i < 14; i++) {
		if (arr[cnt % 2][i]) {
			int tmp = arr[cnt % 2][i];
			arr[cnt % 2][i] = 0;
			arr[(cnt + 1) % 2][10 + cnt] = tmp;
			dfs(cnt + 1, cur + (cnt % 2 ? -tmp : tmp));
			arr[cnt % 2][i] = tmp;
			arr[(cnt + 1) % 2][10 + cnt] = 0;
		}
	}
}
int main() {
	for (int i = 0; i < 10; i++) scanf("%d", &arr[0][i]);
	for (int i = 0; i < 10; i++) scanf("%d", &arr[1][i]);

	dfs(0, 1000);
	printf("%d", ans);

	return 0;
}