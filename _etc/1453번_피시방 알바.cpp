/*
BOJ 1453 - 피시방 알바
https://www.acmicpc.net/problem/1453
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
bool can[101];
int main() {
	int n, x, ans = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		if (!can[x]) can[x] = true;
		else ans++;
	}
	printf("%d", ans);

	return 0;
}