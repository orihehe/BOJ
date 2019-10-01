/*
BOJ 17502 - 클레어와 팰린드롬
https://www.acmicpc.net/problem/17502
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
char st[101];
int main() {
	int n;
	scanf("%d %s", &n, st);
	for (int i = 0; i < n / 2; i++) {
		if (st[i] == '?' && st[n - i - 1] == '?') st[i] = st[n - i - 1] = 'a';
		else if (st[i] == '?') st[i] = st[n - i - 1];
		else if (st[n - i - 1] == '?') st[n - i - 1] = st[i];
	}
	if (st[n / 2] == '?') st[n / 2] = 'a';
	printf("%s", st);

	return 0;
}