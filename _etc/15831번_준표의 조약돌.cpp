/*
BOJ 15831 (https://www.acmicpc.net/problem/15831)
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
char st[300001];
int main() {
	int n, b, w, l, cntB = 0, cntW = 0, mV = 0;
	scanf("%d %d %d", &n, &b, &w);
	scanf("%s", st);
	l = 0;
	for (int i = 0; i < n; i++) {
		if (st[i] == 'B') {
			cntB++;
		}
		else {
			cntW++;
		}
		while (i>l && cntB > b) {
			if (st[l] == 'B') cntB--;
			else if (st[l] == 'W') cntW--;
			l++;
		}
		if (cntW >= w && cntB <= b) mV = max(mV, i - l + 1);
	}
	printf("%d", mV);

	return 0;
}