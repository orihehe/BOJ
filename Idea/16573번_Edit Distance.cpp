/*
BOJ 16573 - Edit Distance
https://www.acmicpc.net/problem/16573
*/
#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int main() {
	char st[2001];
	scanf("%s", st);
	int len = strlen(st), a[2] = { 0,0 };
	for (int i = 1; i < len; i++)
		a[st[i] - '0']++;
	st[0] = (st[0] == '0') + '0';
	for (int i = 1; i < len; i++)
		st[i] = (a[0] > a[1]) + '0';
	printf("%s", st);

	return 0;
}