/*
BOJ 11868 - 님 게임 2
https://www.acmicpc.net/problem/11868

증명 - https://blog.myungwoo.kr/27 (전명우님 블로그)
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int main() {
	int n, x = 0, w;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &w);
		x ^= w;
	}
	if (x == 0) printf("cubelover");
	else printf("koosaga");

	return 0;
}