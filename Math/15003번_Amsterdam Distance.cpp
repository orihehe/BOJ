/*
BOJ 15003 - Amsterdam Distance
https://www.acmicpc.net/problem/15003

반원의 중심을 거쳐가거나, 같은 m선상으로 가서 둘레를 따라가거나.
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
const long double PI = 3.141592653589793238462643383279502884197;
using namespace std;

int main() {
	int n, m, sl, sr, el, er, s, e;
	long double r, ss;
	scanf("%d %d %Lf", &n, &m, &r);
	scanf("%d %d %d %d", &sl, &sr, &el, &er);

	s = min(sr, er);
	e = abs(sl - el);

	ss = r / (long double)m;
	if (s == 0) return !printf("0");
	long double xx = (PI*ss*s) * ((long double)e / n) + ss * abs(sr - er);

	printf("%Lf", min(xx, ss*sr + ss * er));
	
	return 0;
}