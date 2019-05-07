/*
BOJ 16305 - Birthday Boy
https://www.acmicpc.net/problem/16305
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/* 🐣🐥 */
int dp[13];
int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
vector<int> vec, idx;
int prt(int x) {
	for (int i = 1; i <= 12; i++) {
		if (dp[i] < x) {
		}
		else {
			return !printf("%02d-%02d", i, x - dp[i - 1]);
		}
	}
}
int main() {
	int n, a, b, mx;

	for (int i = 1; i <= 12; i++) {
		dp[i] = dp[i - 1] + mon[i];
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%*s %d-%d", &a, &b);
		vec.push_back(dp[a - 1] + b);
	}
	sort(vec.begin(), vec.end());

	if (n == 1) {
		int cur = (vec[0] - 1 + dp[12]) % dp[12];
		if (cur == 0) cur = dp[12];
		return prt(cur);
	}
	mx = (vec[0] + dp[12] - vec[n - 1]) % dp[12];
	idx.push_back((vec[0] - 1 + dp[12]) % dp[12]);
	for (int i = 1; i < vec.size(); i++) {
		if (mx < vec[i] - vec[i - 1]) {
			mx = vec[i] - vec[i - 1];
			idx.clear();
			idx.push_back(vec[i] - 1);
		}
		else if (mx == vec[i] - vec[i - 1]) {
			idx.push_back(vec[i] - 1);
		}
	}
	int cur = dp[9] + 28;
	for (int v : idx) {
		if (v >= cur) {
			return prt(v);
		}
	}
	if (idx[0] == 0) idx[0] = dp[12];
	return prt(idx[0]);

	return 0;
}