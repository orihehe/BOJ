/*
BOJ 10742 - PROSJEK
https://www.acmicpc.net/problem/10742

dp[x] - 부분합
구하려는 값은 (dp[j]-dp[i])/(j-k) 이니 이분탐색으로 (dp[j]-dp[i])/(j-i) >= x
이를 전개하면 dp[j] - x*j >= dp[i] - x*i 이고, i<=j-k 이면 된다.
따라서 j-k 이하의 최솟값을 갱신해가며 조건을 만족하는 값이 있는지를 탐색
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll dp[300001];
int main() {
	int n, k, x;
	double mid, l, r, mn;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		dp[i] = dp[i - 1] + x;
	}
	l = 1, r = 1000000;
	for (int j = 0; j < 100; j++) {
		mid = (l + r) / 2;
		mn = 1000000;
		bool suc = false;
		for (int i = k; i <= n; i++) {
			mn = min(mn, dp[i - k] - mid * (i - k));
			if (mn <= dp[i] - mid * i) {
				suc = true;
				break;
			}
		}
		if (suc)
			l = mid;
		else r = mid;
	}
	printf("%lf", mid);

	return 0;
}