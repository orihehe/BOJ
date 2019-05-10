/*
BOJ 17176 - 암호해독기
https://www.acmicpc.net/problem/17176
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int ori[53], dd[53];
char st[100001];
int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		ori[x]++;
	}
	scanf(" %[^\n]", st);
	for (int i = 0; i < n; i++) {
		if (st[i] == ' ') dd[0]++;
		else if (st[i] >= 'A' && st[i] <= 'Z') dd[st[i] - 'A' + 1]++;
		else dd[st[i] - 'a' + 27]++;
	}
	for (int i = 0; i < 53; i++) {
		if (ori[i] != dd[i]) return !printf("n");
	}
	printf("y");

	return 0;
}