/*
BOJ 16692 (https://www.acmicpc.net/problem/16692)
*/
#include <cstdio>
using namespace std;

int sel[1001];
int main() {
	int n, m, ti = 0, midx, x, mV;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		mV = 987654321;
		for (int j = 1; j <= n; j++) {
			if (mV > sel[j] - ti) {
				mV = sel[j] - ti;
				midx = j;
			}
		}
		ti = sel[midx];
		for (int j = 1; j <= n; j++) {
			sel[j] -= ti;
		}
		sel[midx] = x;
		printf("%d ", midx);
	}
}