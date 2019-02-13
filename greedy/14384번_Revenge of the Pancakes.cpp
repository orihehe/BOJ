/*
BOJ 14384 (https://www.acmicpc.net/problem/14384)

위에서부터 현재위치까지 전체를 토글시켜 모두 +로 만드는 문제
밑에서부터 부호가 다른 시점에서 토글시킨다고 생각하면 된다
*/
#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int main() {
	int t, cnt, len;
	char cake[101], l;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		cnt = 0; l = '+';
		scanf("%s", cake);
		len = strlen(cake);
		for (int j = len-1; j >=0; j--) {
			if (cake[j] != l) {
				cnt++;
				l = cake[j];
			}
		}
		printf("Case #%d: %d\n", i, cnt);
	}

	return 0;
}