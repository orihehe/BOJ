/*
BOJ 14620 (https://www.acmicpc.net/problem/14620)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool f[10][10];
int n, arr[10][10];
int minS = 3001;
void dfs(int cnt, int sum) {
	if (cnt == 3) {
		minS = min(minS, sum);
		return;
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (!f[i][j] && !f[i - 1][j] && !f[i][j - 1]
				&& !f[i + 1][j] && !f[i][j + 1]) {
				int tmp = arr[i][j] + arr[i - 1][j] + arr[i + 1][j]
					+ arr[i][j - 1] + arr[i][j + 1];
				f[i][j] = true;
				f[i - 1][j] = true; f[i + 1][j] = true;
				f[i][j - 1] = true; f[i][j + 1] = true;
				dfs(cnt + 1, sum + tmp);
				f[i][j] = false;
				f[i - 1][j] = false; f[i + 1][j] = false;
				f[i][j - 1] = false; f[i][j + 1] = false;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	dfs(0, 0);
	printf("%d", minS);

	return 0;
}