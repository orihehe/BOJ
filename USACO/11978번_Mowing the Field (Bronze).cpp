/*
BOJ 11978 (https://www.acmicpc.net/problem/11978)

가는 경로에 시간을 기록해주고, 재방문 했을 때 최솟값을 저장
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int b[2001][2001];
int rgo[4] = { -1,0,1,0 };
int cgo[4] = { 0,1,0,-1 };
int main() {
	int n, x, d, r = 1000, c = 1000, t = 0, mV = 987654321;
	char cm;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c %d", &cm, &x);
		if (cm == 'N') d = 0;
		else if (cm == 'E') d = 1;
		else if (cm == 'S') d = 2;
		else if (cm == 'W') d = 3;
		while (x--) {
			t++;
			c += cgo[d];
			r += rgo[d];
			if (b[r][c] == 0) b[r][c] = t;
			else {
				mV = min(mV, t - b[r][c]);
				b[r][c] = t;
			}
		}
	}
	if (mV == 987654321) printf("-1");
	else printf("%d", mV);

	return 0;
}