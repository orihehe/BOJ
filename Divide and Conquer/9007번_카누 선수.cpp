/*
BOJ 9007 - 카누 선수
https://www.acmicpc.net/problem/9007

meet in the middle
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/* 🐣🐥 */
int arr[4][1001];
vector<int> up, dw;
int main() {
	int k, n, t, sz, ans;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &k, &n);
		up.clear(), dw.clear();
		ans = -400000000;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < n; j++) scanf("%d", &arr[i][j]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				up.push_back(arr[0][i] + arr[1][j]);
				dw.push_back(arr[2][i] + arr[3][j]);
			}
		}

		sort(dw.begin(), dw.end());
		sz = dw.size();
		for (int v : up) {
			int idx = lower_bound(dw.begin(), dw.end(), k - v) - dw.begin();
			if (idx < sz && abs(k - ans) > abs(k - v - dw[idx])) ans = v + dw[idx];
			if (idx < sz && abs(k - ans) == abs(k - v - dw[idx])) ans = min(ans, v + dw[idx]);
			idx--;
			if (idx >= 0 && abs(k - ans) > abs(k - v - dw[idx])) ans = v + dw[idx];
			if (idx >= 0 && abs(k - ans) == abs(k - v - dw[idx])) ans = min(ans, v + dw[idx]);
		}
		printf("%d\n", ans);
	}

	return 0;
}