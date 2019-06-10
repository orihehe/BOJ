/*
BOJ 17235 - Good Pizza, Great Pizza
https://www.acmicpc.net/problem/17235

y=x 선상으로 옮긴 뒤 max거리, y=-x 선상으로 옮긴 뒤 max거리 중 큰 것을 변으로 선택한다.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define MAX 2000000000000000000
using namespace std;

/* 🐣🐥 */
bool s1, s2;
int main() {
	int n, x, y;
	ll px = -MAX, pm = MAX, mx = -MAX, mm = MAX, p, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		p = y - x, m = x + y;
		mx = max(mx, p);
		mm = min(mm, p);
		px = max(px, m);
		pm = min(pm, m);
	}

	ll fr = mx - mm;
	ll ff = px - pm;
	if (ff % 2) s2 = true;
	if (fr % 2) s1 = true;

	long double rr = (long double)fr / 2;
	long double rrr = (long double)ff / 2;

	rr = 2 * rr*rr + 1e-7;
	rrr = 2 * rrr*rrr + 1e-7;
	if (rr > rrr) {
		if (s1) printf("%lld.5", (ll)rr);
		else printf("%lld", (ll)rr);
	}
	else {
		if (s2) printf("%lld.5", (ll)rrr);
		else printf("%lld", (ll)rrr);
	}

	return 0;
}