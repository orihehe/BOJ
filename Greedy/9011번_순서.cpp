/*
BOJ 9011 - 순서
https://www.acmicpc.net/problem/9011
*/
#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int prt[100], arr[100];
bool used[100];
int main() {
	int t, n;
	bool ans;
	scanf("%d", &t);
	while (t--) {
		ans = true;
		memset(used, false, sizeof(used));
		memset(prt, 0, sizeof(prt));
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				if (used[j]) continue;
				if (!arr[i]) {
					prt[i] = j + 1;
					used[j] = true;
					break;
				}
				arr[i]--;
			}
			if (!prt[i]) ans = false;
		}
		if (ans)
			for (int i = 0; i < n; i++) printf("%d ", prt[i]);
		else printf("IMPOSSIBLE");
		printf("\n");
	}

	return 0;
}