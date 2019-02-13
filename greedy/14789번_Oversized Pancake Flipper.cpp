/*
BOJ 14789 (https://www.acmicpc.net/problem/14789)

앞에서부터 -가 있다면 쭉 뒤집어준다.
이 과정을 했는데 남은게 모두 +가 아니라면 만들수 없음
*/
#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int main() {
	int t, n, len, cnt, j;
	char cake[1001];
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%s %d", cake, &n);
		len = strlen(cake);
		cnt = 0;
		for (j = 0; j <= len-n; j++) {
			if (cake[j] == '-') {
				cnt++;
				for (int k = j; k < j + n; k++) 
					cake[k] = cake[k] == '-' ? '+' : '-';
			}
		}
		for (j = len - n; j < len; j++) {
			if (cake[j] == '-') {
				printf("Case #%d: IMPOSSIBLE\n", i);
				break;
			}
		}
		if (j == len) printf("Case #%d: %d\n", i, cnt);
	}

	return 0;
}