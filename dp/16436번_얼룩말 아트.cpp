/*
BOJ 16436 - 얼룩말 아트
https://www.acmicpc.net/problem/16436

다이아몬드 토나온다.
-1, 1을 적절히 찍고 잘 해준다.
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int dp[2505][2505], arr[2505][2505], ma[2505][2505], mp[2505][2505];
int main() {
	int n, m, k, r1, c1, r2, c2, cm;
	scanf("%d %d %d", &m, &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &cm);
		if (cm == 1) {
			scanf("%d %d %d %d", &c1, &r1, &c2, &r2);
			r1+=2, c1+=2, r2 += 3, c2 += 3;
			arr[r1][c1]++;
			arr[r1][c2]--;
			arr[r2][c1]--;
			arr[r2][c2]++;
		}
		else {
			scanf("%d %d %d", &c1, &r1, &r2);
			r1+=2, c1+=2;
			ma[r1 - r2][c1]++;
			ma[r1 + 1][c1 - r2 - 1]--;
			ma[r1 + r2 + 2][c1]++;
			ma[r1 + 1][c1 + r2 + 1]--;
			r2--;
			ma[r1 - r2][c1]++;
			ma[r1 + 1][c1 - r2 - 1]--;
			ma[r1 + r2 + 2][c1]++;
			ma[r1 + 1][c1 + r2 + 1]--;
		}
	}
	n+=2, m+=2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = dp[i][j - 1] + arr[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			dp[j][i] += dp[j - 1][i];
		}
	}
	n++;
	for (int i = 1; i <= m; i++) {
		int rp = 1, cp = i;
		while (cp <= m && rp <= n) {
			mp[rp][cp] = mp[rp - 1][cp - 1] + ma[rp][cp];
			cp++; rp++;
		}
	}
	for (int i = 2; i <= n; i++) {
		int rp = i, cp = 1;
		while (cp <= m && rp <= n) {
			mp[rp][cp] = mp[rp - 1][cp - 1] + ma[rp][cp];
			cp++; rp++;
		}
	}

	for (int i = 1; i <= m; i++) {
		int rp = 1, cp = i;
		while (cp >= 1 && rp <= n) {
			mp[rp][cp] += mp[rp - 1][cp + 1];
			cp--; rp++;
		}
	}
	for (int i = 2; i <= n; i++) {
		int rp = i, cp = m;
		while (cp >= 1 && rp <= n) {
			mp[rp][cp] += mp[rp - 1][cp + 1];
			cp--; rp++;
		}
	}
	n-=2, m--;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			if ((mp[i][j] + dp[i][j]) % 2) printf("#");
			else printf(".");
		}
		printf("\n");
	}

	return 0;
}