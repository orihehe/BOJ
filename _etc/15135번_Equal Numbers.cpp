/*
BOJ 15135 - Equal Numbers
https://www.acmicpc.net/problem/15135
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_set>
using namespace std;

/* 🐣🐥 */
bool be[1000001];
int use[1000001];
vector<int> besu, arr;
int ans[1000001];
int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (!use[x]) arr.push_back(x);
		use[x]++;
	}

	sort(arr.begin(), arr.end());
	int sz = arr.size();

	for (int i = 0; i < sz; i++) {
		for (int j = arr[i] * 2; j <= 1000000; j += arr[i])
			if (use[j]) be[i] = 1;
	}

	for (int i = 0; i < sz; i++) {
		if (be[i]) besu.push_back(use[arr[i]]);
	}
	sort(arr.begin(), arr.end(), [](int a, int b) {
		return use[a] < use[b];
	});

	sort(besu.begin(), besu.end());

	if (arr.size() == 1) {
		for (int i = 0; i <= n; i++) printf("1 ");
		return 0;
	}

	int mis, ap;
	ans[0] = sz;

	ap = mis = 0;
	sz = besu.size();
	for (int i = 0; i <= n; i++) {
		if (ap < sz && !besu[ap]) {
			mis++;
			ap++;
		}

		ans[i] = arr.size() - mis;
		if (ap < sz)
			besu[ap]--;
	}
	ap = 0; mis = 0;
	sz = arr.size();
	for (int i = 0; i <= n; i++) {
		if (ap < sz && !use[arr[ap]]) {
			mis++;
			ap++;
		}
		ans[i] = min(ans[i], sz - mis + 1);
		if (ap < sz)
			use[arr[ap]]--;
	}

	for (int i = 0; i <= n; i++) printf("%d ", ans[i]);

	return 0;
}