// BOJ 14175 (https://www.acmicpc.net/problem/14175)
#include <cstdio>
using namespace std;

int main() {
	int m, n, k;
	char st[11][11];
	scanf("%d %d %d", &m, &n, &k);
	for (int i = 0; i < m; i++) {
		scanf("%s", st[i]);
	}
	for (int i = 0; i < m; i++) {
		for (int y = 0; y < k; y++) {
			for (int j = 0; j < n; j++) {
				for (int r = 0; r < k; r++) {
					printf("%c", st[i][j]);
				}
			}
			printf("\n");
		}
	}

	return 0;
}