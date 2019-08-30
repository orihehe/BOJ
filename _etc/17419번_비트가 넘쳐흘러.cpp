/*
BOJ 17419 - 비트가 넘쳐흘러
https://www.acmicpc.net/problem/17419
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
char st[1000001];
int main() {
	int n, cnt = 0;
	scanf("%d %s", &n, st);
	for (int i = 0; i < n; i++) if (st[i] == '1') cnt++;
	printf("%d", cnt);

	return 0;
}