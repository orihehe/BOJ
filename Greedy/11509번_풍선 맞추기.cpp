/*
BOJ 11509 - 풍선 맞추기
https://www.acmicpc.net/problem/11509
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int h[1000002];
int main() {
	int n, x, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (h[x + 1]) {
			h[x + 1]--;
			h[x]++;
		}
		else {
			ans++;
			h[x]++;
		}
	}
	printf("%d", ans);

	return 0;
}