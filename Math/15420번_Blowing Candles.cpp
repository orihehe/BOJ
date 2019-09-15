/*
BOJ 15420 - Blowing Candles
https://www.acmicpc.net/problem/15420

컨벡스 헐로 볼록껍질을 만든 후 
인접한 두 점을 지나는 직선과 가장 먼 점의 거리의 최솟값을 구해준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define pii pair<int,int>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll ccw(pii a, pii b, pii c) {
	return 1LL * (a.first - c.first)*(b.second - c.second)
		- 1LL * (b.first - c.first)*(a.second - c.second);
}
pii arr[200001];
vector<pii> sta;
long double a, b, c;
long double dist(pii x) {
	long double ret = a * x.first + b * x.second + c;
	if (ret < 0) ret = -ret;
	return ret;
}
int main() {
	int n, r;
	scanf("%d %d", &n, &r);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}
	sort(arr, arr + n);
	sort(arr + 1, arr + n, [](pii a, pii b) {
		if (ccw(a, b, arr[0]))
			return ccw(a, b, arr[0]) > 0;
		return a < b;
	});
	sta.push_back(arr[0]);
	sta.push_back(arr[1]);
	for (int i = 2; i < n; i++) {
		while (sta.size() >= 2 && ccw(sta.back(), arr[i], sta[sta.size() - 2]) <= 0)
			sta.pop_back();
		sta.push_back(arr[i]);
	}
	n = sta.size();
	if (n == 2) return !printf("0");

	long double ans = 400000001;
	for (int i = 0; i < n; i++) {
		if (sta[i].first == sta[(i + 1) % n].first) {
			a = 1;
			b = 0;
			c = -sta[i].first;
		}
		else if (sta[i].second == sta[(i + 1) % n].second) {
			a = 0;
			b = 1;
			c = -sta[i].second;
		}
		else {
			a = (long double)(sta[i].second - sta[(i + 1) % n].second) / (sta[i].first - sta[(i + 1) % n].first);
			b = -1;
			c = sta[i].second - a * sta[i].first;
		}
		long double loc = 0;
		int l = 0, r = n - 3, mid;
		while (l <= r) {
			mid = (l + r) / 2;
			loc = max(loc, dist(sta[(i + 2 + mid) % n]));
			loc = max(loc, dist(sta[(i + 3 + mid) % n]));

			if (dist(sta[(i + 2 + mid) % n]) > dist(sta[(i + 3 + mid) % n])) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		loc = max(loc, dist(sta[(i + 2 + mid) % n]));
		loc = max(loc, dist(sta[(i + 3 + mid) % n]));

		ans = min(ans, loc / sqrt(a * a + b * b));
	}

	printf("%.10Lf", ans);
	return 0;
}