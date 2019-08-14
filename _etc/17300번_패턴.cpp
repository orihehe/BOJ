/*
BOJ 17300 - 패턴
https://www.acmicpc.net/problem/17300
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int num[10], arr[10];
int w[10][10];
bool use[10];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		num[arr[i]]++;
		if (num[arr[i]] >= 2) return !printf("NO");
	}
	w[1][3] = w[3][1] = 2;
	w[1][7] = w[7][1] = 4;
	w[3][9] = w[9][3] = 6;
	w[7][9] = w[9][7] = 8;
	w[1][9] = w[9][1] = 5;
	w[3][7] = w[7][3] = 5;
	w[2][8] = w[8][2] = 5;
	w[4][6] = w[6][4] = 5;

	use[arr[0]] = true;
	use[0] = true;
	for (int i = 1; i < n; i++) {
		int ww = w[arr[i - 1]][arr[i]];
		if (!use[ww]) return !printf("NO");
		use[arr[i]] = true;
	}
	printf("YES");

	return 0;
}