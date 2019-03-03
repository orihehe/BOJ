/*
BOJ 16438 - 원숭이 스포츠
https://www.acmicpc.net/problem/16438

구간을 반씩 쪼개어 팀을 나눠준다.
앞구간은 뒷구간과 적이 되니 l==r에 도달하면 모든 애들과 적이 될 수 있다.
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
char ans[7][101];
void dq(int l, int r, bool a, int dep) {
	if (dep == 7)return;
	for (int i = l-1; i < r; i++) {
		if (a) ans[dep][i] = 'A';
		else ans[dep][i] = 'B';
	}
	if (l == r) {
		dq(l, r, a, dep + 1);
	}
	else {
		dq(l, (l + r) / 2, true, dep + 1);
		dq((l + r) / 2 + 1, r, false, dep + 1);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	dq(1, n / 2,true,0);
	dq(n / 2+1, n,false,0);
	for (int i = 0; i < 7; i++) {
		printf("%s\n", ans[i]);
	}

	return 0;
}