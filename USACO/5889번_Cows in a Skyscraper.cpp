/*
BOJ 5889 - Cows in a Skyscraper
https://www.acmicpc.net/problem/5889
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int arr[19], w, n;
pii dp[524288];
int ww[524288];
vector<int> ans[19];
int ap;
pii dfs(int cur) {
	if (cur == 0) return { w, 0 };
	if (dp[cur].first != -1) return dp[cur];
	int t, nx;
	pii ret = { 0,18 };
	for (int i = 0; i < n; i++) {
		t = 1 << i;
		if (cur&t) {
			pii tmp = dfs(cur^t);
			if (tmp.first < arr[i]) {
				tmp.second++;
				tmp.first = w - arr[i];
			}
			else tmp.first -= arr[i];

			if (tmp.second == ret.second) {
				if (tmp.first > ret.first) {
					ret = tmp;
					nx = i;
				}
			}
			else {
				ret = tmp;
				nx = i;
			}
		}
	}
	ww[cur] = nx;
	return dp[cur] = ret;
}
int main() {
	int hap = 0;
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &w);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	pii rr = dfs((int)pow(2, n) - 1);
	for (int i = (int)pow(2, n) - 1; i != 0; i ^= (1 << ww[i])) {
		if (hap + arr[ww[i]] <= w) {
			hap += arr[ww[i]];
			ans[ap].push_back(ww[i]);
		}
		else {
			hap = arr[ww[i]];
			ans[++ap].push_back(ww[i]);
		}
	}
	printf("%d\n", rr.second + 1);
	for (int i = 0; i <= ap; i++) {
		printf("%d ", ans[i].size());
		for (int v : ans[i]) printf("%d ", v + 1);
		printf("\n");
	}

	return 0;
}