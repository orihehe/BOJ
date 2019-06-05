/*
BOJ 1102 (https://www.acmicpc.net/problem/1102)

dp[남은 발전소]로 설정, 모든 켜진 발전소에 대해 안켜진 발전소로 가본다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 801
using namespace std;

/* 🐣🐥 */
int b[17][17];
int dp[1 << 17], cnt, n, x;
int go(int val, int cn) {
	int tmp = MAX;
	if (cn == x) return 0;
	if (dp[val] != -1) return dp[val];
	for (int j = 0, jj = 1; j < n; j++, jj *= 2) {
		if ((val | jj) == val) { // 발전소 돌아간다면
			for (int i = 0, cc= 1; i < n; i++, cc *= 2) {
				// 안 돌아가는 발전소로 가본다
				if ((val | cc) != val) { 
					tmp = min(tmp, go(val + cc, cn + 1) + b[j][i]);
				}
			}
		}
	}
	return dp[val]=tmp;
}
int main() {
	int len, cc = 1, mm = 0;
	char yn[17];
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &b[i][j]);
		}
	}
	scanf("%s %d", yn, &x);
	len = strlen(yn);
	for (int i = 0; i < len; i++, cc*=2) {
		if (yn[i] == 'Y') {
			cnt++;
			mm += cc;
		}
	}
	if (cnt >= x) return !printf("0");
	go(mm, cnt);
	
	if (dp[mm] >= MAX) printf("-1");
	else printf("%d", dp[mm]);

	return 0;
}