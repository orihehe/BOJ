/*
BOJ 16572 - Pixel Triangles
https://www.acmicpc.net/problem/16572

가로로 한번, 대각으로 한번 스위핑 후 세로로 스위핑
*/
#include <iostream>
#define mx 2001
using namespace std;

/* 🐣🐥 */
int r[mx + 2][mx + 2], d[mx + 2][mx + 2], arr[mx+2][mx+2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b, c, ans = 0;
	cin >> n;
	while (n--) {
		cin >> a >> b >> c;
		r[a][b]++;
		r[a][b + c]--;
		d[a + 1][b + c - 1]--;
		d[a + c + 1][b - 1]++;
	}
	for (int i = -mx; i <= mx; i++) {
		for (int j = mx; j >= 0; j--) {
			int y = i + j;
			if (y > mx || y<0) continue;
			d[y][j] += d[y - 1][j + 1];
		}
	}
	for (int i = 0; i <= mx; i++) {
		for (int j = 1; j <= mx; j++) {
			r[i][j] += r[i][j - 1];
		}
	}

	for (int i = 1; i <= mx; i++) {
		for (int j = 0; j <= mx; j++) {
			arr[i][j] += arr[i - 1][j] + r[i][j] + d[i][j];
			if (arr[i][j] > 0) ans++;
		} 
	}
	cout << ans;

	return 0;
}