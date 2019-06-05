/*
BOJ 8925 - GC-비율
https://www.acmicpc.net/problem/8925

평균의 최대값을 먼저 이분탐색으로 찾은 뒤,
그 값으로 pq를 이용하여 가장 짧은 길이를 찾는다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define ll long long
#define pdi pair<double,int>
using namespace std;

/* 🐣🐥 */
ll dp[100001];
char st[100003];
priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
int main() {
	int t, n, m, al, ar;
	double l, r, mid, mn, ans;
	bool suc;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %s", &n, &m, st + 1);
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			dp[i] = dp[i - 1] + (st[i] == '1');
		}
		l = 0, r = 100000;
		al = -1, ar = n;
		while (!pq.empty()) pq.pop();
		for (int i = 0; i < 50; i++) {
			mid = (l + r) / 2;
			mn = 100000;
			suc = false;
			for (int j = m; j <= n; j++) {
				mn = min(mn, dp[j - m] - mid * (j - m));
				if (mn <= dp[j] - mid * j) {
					suc = true;
					break;
				}
			}
			if (suc) {
				l = mid;
				ans = mid;
			}
			else {
				r = mid;
			}
		}

		for (int j = m; j <= n; j++) {
			pq.push({ dp[j - m] - ans * (j - m),j - m });
			while (!pq.empty() && pq.top().first <= dp[j] - ans * j) {
				pdi tmp = pq.top();
				pq.pop();
				if (j - tmp.second < ar - al) {
					ar = j, al = tmp.second;
				}
			}
		}

		printf("%d %d\n", al + 1, ar);
	}

	return 0;
}