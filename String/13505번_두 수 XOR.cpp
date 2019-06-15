/*
BOJ 13505 - 두 수 XOR
https://www.acmicpc.net/problem/13505

수를 2진수로 나타내고, 왼쪽에서부터 최대한 내가 가지지 못한 비트를 가진 원소를 고른다.
trie를 통해 빠르게 해준다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int mp[3000000][2];
int main() {
	int n, x, cnt = 0, tt, nw, tmp, ans = 0, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		nw = tmp = 0;
		for (int j = 29; j >= 0; j--) {
			if (i == 0) break;
			tt = 1 << j;
			b = x & tt ? 1 : 0;
			if (mp[nw][!b]) {
				nw = mp[nw][!b];
				tmp += !b ? tt : 0;
			}
			else {
				nw = mp[nw][b];
				tmp += b ? tt : 0;
			}
		}
		if (i != 0) ans = max(ans, x^tmp);
		nw = 0;
		for (int j = 29; j >= 0; j--) {
			tt = 1 << j;
			b = x & tt ? 1 : 0;
			if (mp[nw][b]) nw = mp[nw][b];
			else {
				mp[nw][b] = ++cnt;
				nw = cnt;
			}
		}
	}
	printf("%d", ans);

	return 0;
}