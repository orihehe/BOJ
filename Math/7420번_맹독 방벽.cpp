/*
BOJ 7420 - 맹독 방벽
https://www.acmicpc.net/problem/7420
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#define pii pair<int,int>
long double PI = 3.141592653589793238462643383279502884197;
using namespace std;

/* 🐣🐥 */
pii arr[1001];
vector<pii> vec;
int ccw(pii a, pii b, pii c) {
	return (a.first - c.first)*(b.second - c.second)
		- (b.first - c.first)*(a.second - c.second);
}
double dist(pii a, pii b) {
	return sqrt((a.first - b.first)*(a.first - b.first)
		+ (a.second - b.second) *(a.second - b.second));
}
double ud(pii a, pii b, pii c) {
	return dist(a, c) * dist(b, c);
}
int inner(pii a, pii b, pii c) {
	return (a.first - c.first)*(b.first - c.first)
		+ (b.second - c.second)*(a.second - c.second);
}
int main() {
	int n, l;
	double ans = 0;
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}
	sort(arr, arr + n);
	sort(arr + 1, arr + n, [](pii a, pii b) {
		if (ccw(a, b, arr[0])) return ccw(a, b, arr[0]) > 0;
		return a.first < b.first;
	});
	vec.push_back(arr[0]); vec.push_back(arr[1]);
	for (int i = 2; i < n; i++) {
		while (vec.size() >= 2 && ccw(vec.back(), arr[i], vec[vec.size() - 2]) <= 0)
			vec.pop_back();
		vec.push_back(arr[i]);
	}
	if (vec.size() == 2) {
		ans += 2 * PI*l;
		ans += 2 * dist(vec[0], vec[1]);
		return !printf("%.0lf", ans);
	}

	vec.push_back(vec[0]);
	vec.push_back(vec[1]);
	int sz = vec.size();
	for (int i = 1; i < sz - 1; i++) {
		double cw = inner(vec[i + 1], vec[i - 1], vec[i]);
		double dw = ud(vec[i + 1], vec[i - 1], vec[i]);
		cw /= dw;
		double dd = acos(cw);
		dd = PI - dd;

		ans += l * dd;
		ans += dist(vec[i], vec[i - 1]);
	}
	printf("%.0lf", ans);

	return 0;
}