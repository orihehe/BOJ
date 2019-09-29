/*
BOJ 13935 - Hamiltonian Hypercube
https://www.acmicpc.net/problem/13935
*/
#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;

/* 🐣🐥 */
void dfs(bool flag, ll pw, ll &a, char st[], int loc) {
	if (pw == 0) return;
	if (st[loc] != flag + '0') {
		a += pw;
		dfs(true, pw / 2, a, st, loc + 1);
	}
	else dfs(false, pw / 2, a, st, loc + 1);
}
int main() {
	int n;
	char le[62], ri[62];
	scanf("%d", &n);
	scanf("%s %s", le, ri);
	ll len = pow(2, n - 1), x = 0, y = 0;
	dfs(false, len, x, le, 0);
	dfs(false, len, y, ri, 0);
	printf("%lld", y - x - 1);

	return 0;
}