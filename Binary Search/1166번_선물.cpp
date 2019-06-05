/*
BOJ 1166 (https://www.acmicpc.net/problem/1166)

선물 박스의 한 변 A를 이분탐색으로 찾는다.
주어진 큰 박스의 각 L, W, H를 A로 나눈 값들의 곱이 넣을 수 있는 선물 개수와 같다.
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