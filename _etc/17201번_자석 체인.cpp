/*
BOJ 17201 - 자석 체인
https://www.acmicpc.net/problem/17201

양 끝 제외 중간이 같은 연속이 있다면 No
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
char st[11];
int main() {
	int n;
	scanf("%d %s", &n, st);
	for (int i = 1; i < 2 * n; i += 2) if (st[i] == st[i + 1]) return !printf("No");
	printf("Yes");

	return 0;
}