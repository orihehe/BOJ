/*
BOJ 1166 (https://www.acmicpc.net/problem/1166)

���� �ڽ��� �� �� A�� �̺�Ž������ ã�´�.
�־��� ū �ڽ��� �� L, W, H�� A�� ���� ������ ���� ���� �� �ִ� ���� ������ ����.
*/
#include <cstdio>
#define ll long long
using namespace std;

int main() {
	ll n;
	double l, w, h, le, ri, mid;
	scanf("%lld %lf %lf %lf", &n, &l, &w, &h);
	le = 0, ri = h;
	for (int i = 0; i < 1000; i++) {
		mid = (le + ri) / 2;
		ll cnt = (ll)(l / mid) * (ll)(w / mid) * (ll)(h / mid);
		if (cnt >= n) {
			le = mid;
		}
		else {
			ri = mid;
		}
	}
	printf("%.10lf", mid);

	return 0;
}